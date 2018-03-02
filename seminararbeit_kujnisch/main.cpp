#include <iostream>
#include <fstream>
#include <header.h>

using namespace std;


int main()
{
    Console console;
    Console consoleList[100];
    ifstream eingabe;
    int consoleCounter=0;

    eingabe.open("//Users//denise//Documents//1_Studium//Semester//5-Semester//2_Medieninfo//BM3//seminararbeit//Seminararbeit_Kujnisch//consoles.xml");
    char tempZeichen;
    // erstes > wird ignoriert damit weitere verarbeitung leichter ist
    for (;;){
        eingabe.get(tempZeichen);
        if ('>'==tempZeichen)
            break;
    }
    for (;;) {
        eingabe.get(console.zeichen);
        if (eingabe.eof()) break;
        console.parsezeichen();
        //pruefung, ob element=4, wenn ja, dann wird naechste konsole befuellt
        if (4==console.element) {
            consoleList[consoleCounter]=console.getConsole();
            cout << "eine neue Konsole wurde geschaffen" << endl;
            cout << consoleList[consoleCounter].console_name << endl;
            cout << consoleList[consoleCounter].console_publisher << endl;
            cout << consoleList[consoleCounter].console_type << endl;
            cout << consoleList[consoleCounter].console_year << endl;
            consoleCounter++;
        }
    }
    eingabe.close();
}
