/**
 * @file logger.cpp
 * @brief Lecture 10.2 
 * handles the declaration of all logging functionality
 * @assignment Lecture 10.2
 * @author Liam Cannon
 * @credit Bilbo 
 * @date 11/9/2020
 * 
*/

#include "logger.h"
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

bool log(std::string msg, std::ofstream& logFile) {
    
    std::string strTime;

    //get time
    time_t logTime = time(0);
    strTime = ctime(&logTime);

    //time off the new line
    int timeSize = strTime.size();
    if(timeSize) {
        strTime[timeSize -1] = ' ';
    }
    //get progrm name

    std::string strProgramName;
    //get pid
    //get hostname
    std::string strHostName;
    if(logFile) {
        //logFile << strTime << strHostName << " " << strProgramName << "[" << pid << " ]: " << msg << std::endl;
        return true;
    }
    else {
        return false;
    }
}
