#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;

int main(int argc, char *argv[], char* env[])
{
    passwd *pws;
    pws = getpwuid(geteuid());
    cout << "user is: " << pws->pw_name << " userid is: "<< pws->pw_uid << endl;

    pid_t pid = getpid();
    string programName = basename(argv[0]);
    cout << "the pid of: " << programName << " is: " << pid << endl;

    return EXIT_SUCCESS;
}