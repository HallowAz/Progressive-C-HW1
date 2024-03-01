#include <iostream>
#include <fstream>
#include "hw1.hpp"

int main(int argc, char* argv[]){
    std::string artistFileName, genderFileName, year;
    const std::string ARTIST_FILENAME_PARAM = "--artistFilename=",
                      GENDER_FILENAME_PARAM = "--genderFilename=",
                      YEAR_PARAM = "--year=";
   
    for (int i = 1; i < argc; ++i) {
        std::string param(argv[i]);
        if (param.find(ARTIST_FILENAME_PARAM) != std::string::npos){
            artistFileName = param.substr(ARTIST_FILENAME_PARAM.size());
        } else if (param.find(GENDER_FILENAME_PARAM) != std::string::npos){
            genderFileName = param.substr(GENDER_FILENAME_PARAM.size());
        } else if (param.find(YEAR_PARAM) != std::string::npos){
            year = param.substr(YEAR_PARAM.size());
        } else{
            std::cout << "invalid params" << std::endl;
        }
    }
    
    if (year > "2024") {
        std::cout << "The year has not come yet" << std::endl;
        return 0;
    }


    try {
        std::cout << livedInThisYear(genderFileName, artistFileName, year) << std::endl;    
    } catch(...) {
        std::cout << "Error: invalid arguments" << std::endl;
    }
    return 0;
}