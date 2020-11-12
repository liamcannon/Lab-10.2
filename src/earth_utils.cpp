/**
 * @file earth_utils.h
 * @brief Lecture 10.2 
 * handles implimentation of earth utils
 * @assignment Lecture 10.2
 * @author Liam Cannon
 * @credit Bilbo 
 * @date 11/9/2020
 * 
*/

#include "earth_utils.h"
int processCSV(std::ifstream& inFile, std::String kmlFileName) {
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount{};

    if(inFile) {
        getline(inFile, strLine);
        
    }
}