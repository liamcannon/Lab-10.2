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
#endif