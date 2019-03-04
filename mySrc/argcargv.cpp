// Name of program argcargv.cpp

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    cout << "You entered " << argc << " arguments:" << endl;

    for(int i = 0; i < argc; ++i)
        cout << argv[i] << endl;

    return 0;
}
