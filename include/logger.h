/**
 * @file logger.h
 * @brief Lecture 10.2 
 * handles the declaration of all logging functionality
 * @assignment Lecture 10.2
 * @author Liam Cannon
 * @credit Bilbo 
 * @date 11/9/2020
 * 
*/

#ifndef LOGGER_H  
#define LOGGER_H
#include <string>
#include <fstream>

/**
 * @brief Lecture 10.2 
 * @date 11/9/2020
 * @return returns a boolean inducating the message was written ok
 * @param msg std:string containing syslog msg
 * @param logFile ofstream reference, validation of this file is expected
*/
bool log(std::string msg, std::ofstream& logFile);

#endif