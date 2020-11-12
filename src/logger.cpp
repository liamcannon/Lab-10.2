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
#include <unistd.h>

using namespace std;

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{

    std::string strTime;
    pid_t pid = getpid();
    time_t logTime = time(0);
    strTime = ctime(&logTime);
    char *strHostName = new char[MAX_LEN];

    gethostname(strHostName, MAX_LEN);

    //time off the new line
    int timeSize = strTime.size();
    if (timeSize)
    {
        strTime[timeSize - 1] = ' ';
    }
    //get progrm name
    //get 

    if(logFile)
    {
        //write to log
        logFile << strTime << strHostName << " " << programName << "[" << pid << "]: " << msg << endl;

        delete[] strHostName;
        return true;
    }
    else
    {
        delete[] strHostName;
        return false;
    }
}
