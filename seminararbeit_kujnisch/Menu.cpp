#include <iostream>
#include <string>
#include <sstream>
#include "header.h"

using namespace std;

// kein rueckgabewert da menustart hier erfolgt
void Menu::startMenu(){
    cout << "menu1" << endl;
    cout << "menu2" << endl;
    cout << "menu3" << endl;
    cout << "help" << endl;

    int myNumber = 0;
    string input = "";

     while (true) {
       cout << "Please enter a valid number: ";
       getline(cin, input);

       // This code converts from string to number safely.
       stringstream myStream(input);
       if (myStream >> myNumber) {
           if (99==myNumber) {
               break;
           }
           // menupunkt 1
           if (0==myNumber) {
               break;
           }
           // menupunkt 2
           if (1==myNumber) {
               break;
           }
           // menupunkt 3
           if (2==myNumber) {
               break;
           }
       }
       cout << "Invalid number, please try again" << endl;
     }
     cout << "You entered: " << myNumber << endl << endl;


}
