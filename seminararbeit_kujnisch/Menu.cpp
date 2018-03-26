#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include "header.h"

using namespace std;

// kein rueckgabewert da menustart hier erfolgt
void Menu::startMenu(Console consoleList[], Game gameList[]){
    startMenuAusgabe();
    string input = "";
    // eingabe der menupunkte
    // suche
    string menuEingabe_s= "s";
    string menuEingabe_suche= "suche";
    // export
    string menuEingabe_e= "e";
    string menuEingabe_export= "export";
    // hilfe
    string menuEingabe_h= "h";
    string menuEingabe_hilfe= "hilfe";

     while (true) {
       getline(cin, input);
       // benutzerEingabe aus getline command
      // stringstream benutzerEingabe(input);
           // suche
           if (0==strcmp(menuEingabe_s.c_str(), input.c_str()) || 0==strcmp(menuEingabe_suche.c_str(), input.c_str())) {
               suche(consoleList, gameList);
               cout << "Mist, wir sind zurueck im hauptmenu" << endl;
           }
           // export
           if (0==strcmp(menuEingabe_e.c_str(), input.c_str()) || 0==strcmp(menuEingabe_export.c_str(), input.c_str())) {
               break;
           }
           // hilfe
           if (0==strcmp(menuEingabe_h.c_str(), input.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), input.c_str())) {
               break;
           }
     }
    }

void Menu::suche(Console consoleList[], Game gameList[]){
    suchMenuAusgabe();
    // erstellen der parameter
    // suche
    string inputSuche = "";
    string gameSuche = "";
    // game
    string menuEingabe_g= "g";
    string menuEingabe_game= "game";
    // console
    string menuEingabe_c= "c";
    string menuEingabe_console= "console";
    // zurueck
    string menuEingabe_z= "z";
    string menuEingabe_zurueck= "zurueck";
    // hilfe
    string menuEingabe_h= "h";
    string menuEingabe_hilfe= "hilfe";

    while (true) {
      getline(cin, inputSuche);
           // suche nach
          // game
          if (0==strcmp(menuEingabe_g.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_game.c_str(), inputSuche.c_str())) {
              cout << "Gib einen Suchnamen ein! Achtung: case sensitive!" << endl;
              getline(cin, gameSuche);
              cout << "nach folgendem Begriff wird gesucht: \'" +gameSuche + "\'" << endl;
              bool nixGefunden=true;
              for(unsigned i = 1; i <= (sizeof(Game)/sizeof(gameList)); i++) {
                   if (std::string::npos!=gameList[i].gamename.find(gameSuche)) {
                          cout << gameList[i].gamename << endl;
                        nixGefunden=false;
                   }
              }
              if (nixGefunden) {
                  cout << "Leider nix gefunden." << endl;
              }
              suchMenuAusgabe();
          }
          // console
          if (0==strcmp(menuEingabe_c.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_console.c_str(), inputSuche.c_str())) {
              break;
          }
          // zurueck
          if (0==strcmp(menuEingabe_z.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_zurueck.c_str(), inputSuche.c_str())) {
              break;
          }
          // hilfe
          if (0==strcmp(menuEingabe_h.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), inputSuche.c_str())) {
              break;
          }
    }
    }

void Menu::suchMenuAusgabe(){
    cout << "------------------------------------" << endl;
    cout << "Wonach moechtest du suchen?" << endl;
    cout << "(g)ames suchen" << endl;
    cout << "(c)onsoles suchen" << endl;
    cout << "(z)urueck" << endl;
    cout << "(h)ilfe" << endl;
}

void Menu::startMenuAusgabe(){
    cout << "------------------------------------" << endl;
    cout << "Was moechtest du machen?" << endl;
    cout << "(s)uche" << endl;
    cout << "(e)xport" << endl;
    cout << "(h)ilfe" << endl;
}
