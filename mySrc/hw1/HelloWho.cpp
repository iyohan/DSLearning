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
    string name = "", space = " ";
    int i;

    if(argc < 2){
        while(1){
            cout << "Enter a name: ";
            getline(cin, name);
            if(name == "")
                break;
            cout << "Hello " << name << "!" << endl;
        }
        cout << "Hello World!";
    }
    else{
        for(i = 1; i < argc; i++){
            name += argv[i];
            if(i < argc - 1)
                name += space;
        }
        cout << "Hello " << name << "!" << endl;
    }

    return 0;
}
