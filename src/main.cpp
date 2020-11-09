#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;

int main(int argc, char *argv[], char* env[])
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string logValue;
    string kmlValue;
    bool optErr = true;
    while((opt = getopt(argc, argv, "c:k:")) != EOF) {
        switch(opt) {
            case 'k':
                kmlFlag = true;
                kmlValue = atoi(optarg);
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

    

    cout << "The count is: " << kmlValue << " and the logfile is: "<< logValue << endl;
    cout << "optErr: " << optErr << endl;
    return EXIT_SUCCESS;
}