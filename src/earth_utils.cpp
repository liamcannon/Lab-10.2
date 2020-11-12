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
using namespace std;

int processCSV(std::ifstream &inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount{};

    if (inFile)
    {
        getline(inFile, strLine);
        ofstream kmlFile(kmlFileName);
        kmlFile << KML_OPEN_TAG;

        while (getline(inFile, strLine))
        {
            //cout << strLine << endl;
            stringstream sstream(strLine);
            getline(sstream, strCountry, ',');
            getline(sstream, strCapital, ',');
            getline(sstream, strLat, ',');
            getline(sstream, strLong, ',');
            //cout << strCountry << "~" << strCapital << strLat << "~" << strLong << endl;
            writePlacemark(kmlFile, strCapital + ", " + strCountry, strLat, strLong);
            recordCount++;
        }
        kmlFile << KML_CLOSE_TAG;
    }
    return recordCount;
}

void writePlacemark(std::ofstream &kmlFile, std::string name, std::string lat, std::string lon)
{
    kmlFile << PLACEMARK_OPEN_TAG << NAME_OPEN_TAG << name << NAME_CLOSE_TAG << POINT_COORD_OPEN << lon << "," << lat << POINT_COORD_CLOSE << PLACEMARK_CLOSE_TAG;
}
