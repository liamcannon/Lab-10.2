/**
 * @file earth_utils.h
 * @brief Lecture 10.2 
 * handles parsing lat/long csv file and conversion of that file to kml
 * @assignment Lecture 10.2
 * @author Liam Cannon
 * @credit Bilbo 
 * @date 11/9/2020
 * 
*/
#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief Lecture 10.2 
 * @date 11/9/2020
 * @return returns the number of records processed
 * @param inFile ifstream to an opened and validated csv
 * @param kmlFileName std::string containing the name of the kml file
 * @param logFile ofstream reference
*/
int processCSV(std::ifstream& inFile, std::string kmlFileName);

void writePlacemark(std::ofstream& kmlFile, std::string name, std::string lat, std::string lon);

const std::string KML_OPEN_TAG = "<?xml version=\"1.o\" encoding=\"UTF-8\"?>\n"
                          "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n"
                          "<Document>\n";
const std::string KML_CLOSE_TAG = "</Document>\n</kml>";
const std::string PLACEMARK_OPEN_TAG = "<Placemark>\n";
const std::string PLACEMARK_CLOSE_TAG = "</Placemark>\n";
const std::string NAME_OPEN_TAG = "<name>\n";
const std::string NAME_CLOSE_TAG = "</name>\n";
const std::string POINT_COORD_OPEN = "<Point><coordinates>";
const std::string POINT_COORD_CLOSE = "</coordinates></Point>\n";
#endif