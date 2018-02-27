#include <iostream>
#include "header.h"

using namespace std;

Console Console::getConsole(){
    Console console;
    console.console_name=console_name;
    console.console_publisher=console_publisher;
    console.console_type=console_type;
    console.console_year=console_year;
    element=0;
    return console;
}

int Console::parsezeichen () {
    switch(zeichen) {
        case '>':
        krokodilcounter++;
        zaehler=0;
        if (4==krokodilcounter && -1==element) {
            element++;
            krokodilcounter=0;
         }
        if (2==krokodilcounter && -1!=element) {
            element++;
            krokodilcounter=0;
        }
        break;

        case '<':
            puffer[zaehler]='\0';
            if (0==element){
                console_name=puffer;
            }
            if (1==element){
                console_publisher=puffer;
            }
            if (2==element){
                console_year=puffer;
            }
            if (3==element){
                console_type=puffer;
                element++;
            }
           cout << puffer << endl;
           cout << "Element: " << element << endl;
            break;
        default:
           puffer[zaehler]=zeichen;
           zaehler++;
           break;
    }
    return 0;
}


