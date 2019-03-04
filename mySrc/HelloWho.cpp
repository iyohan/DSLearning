/*
On my honour,  I pledge that I have neither received nor provided
improper assistance in the completion of this assignment.
Signed: John Lee    section: ECE20010 (02)  Student Number: 21800815
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 1){
        cout << "Enter a name: "
        
    }
    else{
        cout << "Hello "
        for(int i = 1; i < argc; i++){
            cout << argv[i];
        }
    }

    return EXIT_SUCCESS;
}
