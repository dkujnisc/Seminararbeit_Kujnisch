#include <iostream>
#include <string>
#include <sstream>
#include "header.h"
#include <cstring>

using namespace std;

// kein rueckgabewert da menustart hier erfolgt
void Menu::startMenu(Console consoleList[], Game gameList[]){
    cout << "(s)uchen" << endl;
    cout << "(e)xportieren" << endl;
    cout << "(h)ilfe" << endl;

    string input = "";
    // eingabe der menupunkte
    string menuEingabe_s= "s";
    string menuEingabe_suche= "suche";

    string menuEingabe_e= "e";
    string menuEingabe_export= "export";

    string menuEingabe_h= "h";
    string menuEingabe_hilfe= "hilfe";

     while (true) {
       cout << "Please enter a valid number: ";
       getline(cin, input);
       cout << input << endl;
       // benutzerEingabe aus getline command
      // stringstream benutzerEingabe(input);
           if (0==strcmp(menuEingabe_s.c_str(), input.c_str()) || 0==strcmp(menuEingabe_suche.c_str(), input.c_str())) {
               // hier kommt die suche hin
               suche(consoleList, gameList);
               break;
           }
           if (0==strcmp(menuEingabe_e.c_str(), input.c_str()) || 0==strcmp(menuEingabe_export.c_str(), input.c_str())) {
               break;
           }
           if (0==strcmp(menuEingabe_h.c_str(), input.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), input.c_str())) {
               break;
           }
     }
    }

void Menu::suche(Console consoleList[], Game gameList[]){
    cout << "(g)ames suchen" << endl;
    cout << "(c)onsoles suchen" << endl;
    cout << "(z)urueck" << endl;
    cout << "(h)ilfe" << endl;

    string inputSuche = "";
    string gameSuche = "";
    string menuEingabe_g= "g";
    string menuEingabe_game= "games";

    string menuEingabe_c= "c";
    string menuEingabe_console= "consoles";

    string menuEingabe_z= "z";
    string menuEingabe_zurueck= "zurueck";

    string menuEingabe_h= "h";
    string menuEingabe_hilfe= "hilfe";

    while (true) {
      getline(cin, inputSuche);
          if (0==strcmp(menuEingabe_g.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_game.c_str(), inputSuche.c_str())) {
              getline(cin, gameSuche);
              for(unsigned i = 1; i <= (sizeof(Game)/sizeof(*gameList)); i++) {
                  if(0==strcmp(gameSuche.c_str(), gameList[i].eigenebewertung.c_str())){
                          cout << gameList[i].gamename << endl;
              }
              }
              break;
          }
          if (0==strcmp(menuEingabe_c.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_console.c_str(), inputSuche.c_str())) {
              break;
          }
          if (0==strcmp(menuEingabe_z.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_zurueck.c_str(), inputSuche.c_str())) {
              break;
          }
          if (0==strcmp(menuEingabe_h.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), inputSuche.c_str())) {
              break;
          }

      cout << "Invalid number, please try again" << endl;
    }
    }
