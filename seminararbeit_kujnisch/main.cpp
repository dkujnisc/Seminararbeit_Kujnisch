#include <iostream>
#include <fstream>
#include <map>
#include <list>

using namespace std;

//list< map<string,string> > listOfMaps;
map<string,string> readGame(){
    map<string,string> result;
    result.insert(pair<string,string>('gamename','Super Mario Land'));
    result.insert(pair<string,string>('gamenamy','Super Mario Land'));
    result.insert(pair<string,string>('gamenamk','Super Mario Land'));
    result.insert(pair<string,string>('gamenamo','Super Mario Land'));
    result.insert(pair<string,string>('gamenamp','Super Mario Land'));
    result.insert(pair<string,string>('gamenamt','Super Mario Land'));
    result.insert(pair<string,string>('gamenami','Super Mario Land'));
    return result;
}
void addGame(map<string,string> gameMap){
    listOfMaps[0]=gameMap;
}



int main()
{
    ifstream eingabe;
    list< map<string,string> > listOfMaps;

    listOfMaps[0]=readGame();

     //map<string, map<string,string>>::iterator i = m.find("hello");
      //assert(i != m.end());
    for (list<map<string,string>>::iterator it = listOfMaps.begin(); it != listOfMaps.end(); it++)
        cout << *it << 'xxx';
      //std::cout << "Key: " << i->first << " Value: " << i->second << '\n';


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

    cout << "Hello Worlk!" << endl;
    return 0;
}
