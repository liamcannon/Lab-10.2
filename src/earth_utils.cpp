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

        while (getline(inFile, strLine))
        {
            //cout << strLine << endl;
            stringstream sstream(strLine);
            getline(sstream, strCountry, ',');
            getline(sstream, strCapital, ',');
            getline(sstream, strLat, ',');
            getline(sstream, strLong, ',');
            //cout << strCountry << "~" << strCapital << strLat << "~" << strLong << endl;
        }
    }
    return recordCount;
}

void writePlacemark(std::ofstream &kmlFile, std::string name, std::string lat, std::string lon)
{
    const string KML_OPEN_TAG = "<?xml version=\"1.o\" encoding=\"UTF-8\"?>\n"
                          "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n"
                          "<Document>\n";
    const string KML_CLOSE_TAG = "</Document>\n</kml>";
    const string PLACEMARK_OPEN_TAG = "<Placemark>\n";
    const string PLACEMARK_CLOSE_TAG = "</Placemark>\n";
    const string NAME_OPEN_TAG = "<name>\n";
    const string NAME_CLOSE_TAG = "</name>\n";
    const string POINT_COORD_OPEN = "<Point><coordinates>";
    const string POINT_COORD_CLOSE = "</coordinates></Point>\n";

    kmlFile << PLACEMARK_OPEN_TAG << NAME_OPEN_TAG << name << NAME_CLOSE_TAG << POINT_COORD_OPEN << lon << "," << lat << POINT_COORD_CLOSE << PLACEMARK_CLOSE_TAG;
}
