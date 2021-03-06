#include <iostream>
#include "header.h"

using namespace std;

Console Console::getConsole(){
    Console console;
    console.id=id;
    console.console_name=console_name;
    console.attribut1=attribut1;
    console.attribut2=attribut2;
    console.console_publisher=console_publisher;
    console.console_type=console_type;
    console.console_year=console_year;
    element=-1;
    return console;
}

int Console::parsezeichen () {
    switch(zeichen) {
        case '\'':
        // attributFlag hier initial = false
        // negieren des bool-wertes attributFlag = true
        attributFlag=!attributFlag;
        if (attributFlag) {
            zaehler=0;
            attributcounter++;
        } else {
            puffer[zaehler]='\0';
            if (0==attributcounter) {
                id=puffer;
            }
            if (1==attributcounter) {
                attribut1=puffer;
            }
            if (2==attributcounter) {
                attribut2=puffer;
                // zuruecksetzen auf initialzustand
                attributcounter=-1;
            }
        }
        break;

        case '>':
        krokodilcounter++;
        zaehler=0;
        if (4==krokodilcounter && -1==element) {
            element++;
            krokodilcounter=0;
            start=true;
         }
        else if (2==krokodilcounter && -1!=element) {
            element++;
            krokodilcounter=0;
            start=true;
        }
        break;

        case '<':
            if (start) {
                puffer[zaehler]='\0';
                if (0==element){
                    console_name=puffer;
                    //cout << "Console_Name: " << console_name << endl;
                }
                if (1==element){
                    console_publisher=puffer;
                    //cout << "Console_Publisher: " << console_publisher << endl;
                }
                if (2==element){
                    console_year=puffer;
                    //cout << "Console_Year: " << console_year << endl;
                }
                if (3==element){
                    console_type=puffer;
                    //cout << "Console_Type: " << console_type << endl;
                    element++;
                }
               start=false;
            }
            break;
        default:
           puffer[zaehler]=zeichen;
           zaehler++;
           break;
    }
    return 0;
}


