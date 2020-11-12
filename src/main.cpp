#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include <sstream>
#include <logger.h>
#include <earth_utils.h>

using namespace std;

int main(int argc, char *argv[])
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string logValue;
    string kmlValue;
    bool optErr = true;
    string programName = basename(argv[0]);

    while((opt = getopt(argc, argv, "k:l:")) != EOF) {
        switch(opt) {
            case 'k':
                kmlFlag = true;
                kmlValue = optarg;
                break;
            case 'l':
                logFlag = true;
                logValue = optarg;
                break;
            default:
                optErr = true;
                break;
        }
    }
    cout << "flags * countFlag: " << kmlFlag << " logFlag: " << logFlag << endl;

    if(kmlFlag && logFlag) {
        cout << "flags set" << endl;
        if(logValue.empty() || kmlValue.empty()) {
            optErr = true;
            cout << "option arguments are not set" << endl;
        }
        else {
            optErr = false;
        }
    }
    else {
        cout << "error - flags aren't set" << endl;
        optErr = true;
    }

    if(optErr) {
        return EXIT_FAILURE;
    }

    // all is good here

    

    cout << "The kml file is: " << kmlValue << " and the logfile is: "<< logValue << endl;
    cout << "optErr: " << optErr << endl;

    ofstream logFile(logValue);
    log("The kmlfile is: " + kmlValue + " and the logfile is: " + logValue, programName, logFile);

    ifstream fileIn(kmlValue);
    if(fileIn) {
        int recordCount = processCSV(fileIn, kmlValue + ".kml");
        fileIn.close();
        if(recordCount) {
            cout << recordCount << "records processed" << endl;
            optErr = false;
        }
        else {
            optErr = true;
        }
    }
    else {
        optErr = true;
    }
    return optErr;
}