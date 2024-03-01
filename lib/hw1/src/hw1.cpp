#include "hw1.hpp"

std::string& operator >>(std::string& is, std::string& str){
    str.clear();
    int i = 0;
    const char separator = '\t';

    for (; is[i] != separator && i < is.size(); ++i){
        str.push_back(is[i]);
    }
    if (i != is.size()) {
        is = is.substr(i + 1);
        return is;
    }
    is.clear();
    return is;
}

std::string getIdGender(const std::string& genderFileName, const std::string& gender) {
    std::string genderLine, id, name;
    std::ifstream genderFile(genderFileName);
    if (genderFile.is_open()) {
        while (!genderFile.eof()) {
            getline(genderFile, genderLine);
            genderLine >> id;
            genderLine >> name;
            if (name == gender) {
                genderFile.close();
                return id;
            }
        }
    }
    id.clear();
    genderFile.close();
    return id;
}

bool checkGender(const std::string& genderID, const std::string& maleID, const std::string& femaleID) {
    return genderID == maleID || genderID == femaleID;
}

bool isBorn(const std::string& birthYear, const std::string& year) {
    const std::string NAN("\\N");
    if (birthYear == NAN || birthYear > year) {
        return false;
    } 
    
    return true;
}

bool isDead(const std::string& deathYear, const std::string& year) {
    const std::string NAN("\\N");
    if (deathYear < year) {
        return false;
    } 

    return true;
}


int livedInThisYear(const std::string& genderFileName, const std::string& artistFileName, const std::string& year) {
    const std::string MALE = "Male", FEMALE = "Female";
    std::string maleID, femaleID;
    maleID = getIdGender(genderFileName, MALE);
    femaleID = getIdGender(genderFileName, FEMALE);
    if (maleID.empty() || femaleID.empty()) {
        throw std::string("Problems with gender id");
    }

    std::ifstream artistFile(artistFileName);
    std::string artistLine, birthYear, deathYear, genderId, temp;
    int count = 0;
    if (artistFile.is_open()){
        while (!artistFile.eof()){
            getline(artistFile, artistLine);
            for (int i = 0; i < 13; ++i) {
                switch (i) {
                    case 4:
                        artistLine >> birthYear;
                        break;
                    case 7:
                        artistLine >> deathYear;
                        break;
                    case 12:
                        artistLine >> genderId;
                        break;
                    default:
                        artistLine >> temp;
                }
            }
            if (checkGender(genderId, maleID, femaleID) && isBorn(birthYear, year) && isDead(deathYear, year)) {
                ++count;
            }
        }
    }
    artistFile.close();
    return count;
}