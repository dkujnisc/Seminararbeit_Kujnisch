#include <iostream>
#include <fstream>
#include <map>
#include <list>

#include <Console.h>

using namespace std;


int main()
{
    Console console;
    ifstream eingabe;

    eingabe.open("//Users//denise//Documents//1_Studium//Semester//5-Semester//2_Medieninfo//BM3//seminararbeit//Seminararbeit_Kujnisch//consoles.xml");
    for (denise.zaehler=0,denise.zustand=0;;) {
        eingabe.get(denise.zeichen);
        if (eingabe.eof()) break;
        denise.parsezeichen();
    }
    eingabe.close();
}
