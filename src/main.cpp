#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "count of arguments: " << argc << endl;
    cout << "argument vector item 1: " << argv[0] << endl;
    for(int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    cout << "Lab 10.2 Demo" << endl;
    return EXIT_SUCCESS;
}