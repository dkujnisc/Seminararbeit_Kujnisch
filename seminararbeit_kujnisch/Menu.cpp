#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <chrono>
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
    // beenden
    string menuEingabe_b= "b";
    string menuEingabe_beenden= "beenden";

     while (true) {
       getline(cin, input);
       // benutzerEingabe aus getline command
      // stringstream benutzerEingabe(input);
           // suche
           if (0==strcmp(menuEingabe_s.c_str(), input.c_str()) || 0==strcmp(menuEingabe_suche.c_str(), input.c_str())) {
               suche(consoleList, gameList);
               startMenuAusgabe();
           }
           // export
           if (0==strcmp(menuEingabe_e.c_str(), input.c_str()) || 0==strcmp(menuEingabe_export.c_str(), input.c_str())) {
                 //cout << "Gib einen Exportdateinamen ein!" << endl;
                 //string dateiName = "";
                 //getline(cin, dateiName);
                 //cout << "Deine Datei wird unter folgendem Pfad gespeichert: //Users//denise//Dokumente//" + dateiName + ".xml" << endl;

               // quelle: https://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
               // timestamp für exportdateien
               std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(
                    std::chrono::system_clock::now().time_since_epoch());
               ofstream filestr;
               //filestr.open ("//Users//denise//Dokumente//export" + std::to_string(ms.count()) + ".xml");

               // quelle: https://stackoverflow.com/questions/31860405/how-to-concatenate-a-string-with-chronomilliseconds
               // unwandlung ms in string
               filestr.open ("//Users//denise//Documents//export" + std::to_string(ms.count()) + ".xml");
               std::streambuf *coutbuf = std::cout.rdbuf();
               cout.rdbuf(filestr.rdbuf());
               cout << "Wir sind einfach die Aller Aller Aller GEILSTEN!";
               // wiederherstellung des alten coutbuf
               std::cout.rdbuf(coutbuf);
               // zum abschliessen der datei; aehnlich wie speichern
               filestr.close();
               cout << "Export war erfolgreich" << endl;
               cout << "Folgende Datei wurde geschrieben://Users//denise//Documents//export" + std::to_string(ms.count()) + ".xml" << endl;
               startMenuAusgabe();
           }
           // hilfe
           if (0==strcmp(menuEingabe_h.c_str(), input.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), input.c_str())) {
               cout << "Gib den in Klammern stehenden Buchstaben an oder das Wort." << endl;
               cout << "Beispiel:(b)eenden" << endl;
               cout << "Hier musst Du b oder beenden eingeben." << endl;
           }
           // beenden
           if (0==strcmp(menuEingabe_b.c_str(), input.c_str()) || 0==strcmp(menuEingabe_beenden.c_str(), input.c_str())) {
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
    string consoleSuche = "";
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
              cout << "Gib einen Suchnamen ein! Achtung: case sensitive!" << endl;
              getline(cin, consoleSuche);
              cout << "nach folgendem Begriff wird gesucht: \'" + consoleSuche + "\'" << endl;
              bool nixGefunden=true;
              for(unsigned i = 1; i <= (sizeof(Console)/sizeof(consoleList)); i++) {
                   if (std::string::npos!=consoleList[i].console_name.find(consoleSuche)) {
                          cout << consoleList[i].console_name << endl;
                        nixGefunden=false;
                   }
              }
              if (nixGefunden) {
                  cout << "Leider nix gefunden." << endl;
              }
              suchMenuAusgabe();
          }
          // zurueck
          if (0==strcmp(menuEingabe_z.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_zurueck.c_str(), inputSuche.c_str())) {
              break;
          }
          // hilfe
          if (0==strcmp(menuEingabe_h.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), inputSuche.c_str())) {
              cout << "Gib den in Klammern stehenden Buchstaben an oder das Wort." << endl;
              cout << "Beispiel:(g)ames suchen" << endl;
              cout << "Hier musst Du g oder games eingeben." << endl;
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
    cout << "(b)eenden" << endl;
}
