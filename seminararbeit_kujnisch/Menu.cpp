#include <iostream>
#include <string>
#include <sstream>
#include "header.h"

using namespace std;

// kein rueckgabewert da menustart hier erfolgt
void Menu::startMenu(){
    cout << "(s)uchen" << endl;
    cout << "(e)xportieren" << endl;
    cout << "(h)ilfe" << endl;

    string input = "";

     while (true) {
       cout << "Please enter a valid number: ";
       getline(cin, input);
       cout << input << endl;
       // benutzerEingabe aus getline command
      // stringstream benutzerEingabe(input);
       /*    if (99==myNumber) {
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
           */
       cout << "Invalid number, please try again" << endl;
     }
     //cout << "You entered: " << myNumber << endl << endl;


}
