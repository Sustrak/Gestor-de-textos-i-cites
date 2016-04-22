#include <iostream>
#include <string>
using namespace std;

bool checkthepass(string pass){
  if (pass == "ritosucksdicks") return true;
  return false;
}

int main(){
  string pass;
  while (cin >> pass){
    if(checkthepass(pass)) break;
    cout << "try again !" << endl;
  }
  cout << "mom get the fucking camera" << endl;
}
