#include <iostream>
#include <fstream>
#include <header.h>

using namespace std;


int main()
{
    Console console;
    ifstream eingabe;

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
    }
    eingabe.close();
}
