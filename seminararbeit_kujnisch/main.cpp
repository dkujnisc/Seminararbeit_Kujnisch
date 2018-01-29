#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream eingabe;

    char zeichen;
    //int i;
   //char puffer[100];
   // int zustand=0;

    eingabe.open("//Users//denise//Documents//1_Studium//Semester//5-Semester//2_Medieninfo//BM3//seminararbeit//Seminararbeit_Kujnisch//games.xml");

    for (i=0;;){
        if (eingabe.eof())
        break;
        eingabe.get(zeichen);
    }

    cout << "Hello World!" << endl;
    return 0;
}
