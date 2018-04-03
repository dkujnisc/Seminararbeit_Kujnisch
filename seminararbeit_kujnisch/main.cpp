#include <iostream>
#include <fstream>
#include <header.h>

using namespace std;

int main()
{
    Console console;
    // uebergabeparameter der suche
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
            // cout << "eine neue Konsole wurde geschaffen" << endl;
           // cout << consoleList[consoleCounter].console_name << endl;
           // cout << consoleList[consoleCounter].id << endl;
           // cout << consoleList[consoleCounter].attribut1 << endl;
            //cout << consoleList[consoleCounter].attribut2 << endl;
           // cout << consoleList[consoleCounter].console_publisher << endl;
           // cout << consoleList[consoleCounter].console_type << endl;
           // cout << consoleList[consoleCounter].console_year << endl;
            consoleCounter++;
        }
    }
    eingabe.close();

    Game game;
    Game gameList[100];
    ifstream eingabeGames;
    int gameCounter=0;

    eingabeGames.open("//Users//denise//Documents//1_Studium//Semester//5-Semester//2_Medieninfo//BM3//seminararbeit//Seminararbeit_Kujnisch//games.xml");
    for (;;){
        eingabeGames.get(tempZeichen);
        if ('>'==tempZeichen)
            break;
    }
    for (;;) {
        eingabeGames.get(game.zeichen);
        if (eingabeGames.eof()) break;
        game.parsezeichen();
        //pruefung, ob element=4, wenn ja, dann wird naechste konsole befuellt
        if (7==game.element) {
            gameList[gameCounter]=game.getGame();
          //  cout << "ein neues Game wurde geschaffen" << endl;
           // cout << gameList[gameCounter].gamename << endl;
           // cout << gameList[gameCounter].gameconsole << endl;
           // cout << gameList[gameCounter].gameyear << endl;
           // cout << gameList[gameCounter].gamepublisher << endl;
           // cout << gameList[gameCounter].gamemode << endl;
           // cout << gameList[gameCounter].gamegenre << endl;
           // cout << gameList[gameCounter].eigenebewertung << endl;
            gameCounter++;
        }
    }
    eingabeGames.close();
    Menu menu;
    menu.startMenu(consoleList, gameList);
}
