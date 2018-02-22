#include <iostream>
#include "header.h"

using namespace std;

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
            cout << puffer <<endl;
            break;
        default:
           puffer[zaehler]=zeichen;
           zaehler++;
           break;
    }
    return 0;
}
