#include "nowic.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  cout << "Hi, I'm Parrot! I can mimic you all day" << endl;

  bool isKilled = false;

  while(!isKilled){
    cout << "Enter 'shot' to kill the parrot, otherwise parrot mimics you all day." << endl;
    string trigger = GetString();

    if(trigger == "shot"){
      cout << "Bang!" << endl;
      break;
    }

    cout << trigger << "~~" <<endl;
  }

  return 0;
}
