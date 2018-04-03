#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
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
                 cout << "Gib einen Exportdateinamen ein!" << endl;
                 string dateiName = "";
                 getline(cin, dateiName);
                 cout << "Deine Datei wird unter folgendem Pfad gespeichert: /Users/denise/Documents/" + dateiName + ".xml" << endl;
               ofstream filestr;
               filestr.open ("//Users//denise//Documents//" + dateiName + ".xml");
               std::streambuf *coutbuf = std::cout.rdbuf();
               cout.rdbuf(filestr.rdbuf());
               convert(consoleList, gameList);
               // wiederherstellung des alten coutbuf
               std::cout.rdbuf(coutbuf);
               // zum abschliessen der datei; aehnlich wie speichern
               filestr.close();
               cout << "------------------------------------" << endl;
               cout << "Export war erfolgreich" << endl;
               cout << "Folgende Datei wurde geschrieben://Users//denise//Documents//" + dateiName + ".xml" << endl;
               cout << "------------------------------------" << endl;
               startMenuAusgabe();
           }
           // hilfe
           if (0==strcmp(menuEingabe_h.c_str(), input.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), input.c_str())) {
               cout << "------------------------------------" << endl;
               cout << "Gib den in Klammern stehenden Buchstaben oder das Wort an." << endl;
               cout << "Beispiel:(b)eenden" << endl;
               cout << "Hier gibst Du b oder beenden ein." << endl;
               cout << "------------------------------------" << endl;
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

              // parameter erstellen zum vergleich mit usereingabe
              // name
              string menuEingabe_n= "n";
              string menuEingabe_name = "name";
              // console
              string menuEingabe_c= "c";
              string menuEingabe_console = "console";
              // year
              string menuEingabe_y= "y";
              string menuEingabe_year = "year";
              // publisher
              string menuEingabe_p= "p";
              string menuEingabe_publisher = "publisher";
              // mode
              string menuEingabe_m= "m";
              string menuEingabe_mode = "mode";
              // genre
              string menuEingabe_g= "g";
              string menuEingabe_genre = "genre";
              // eigenebewertung
              string menuEingabe_e= "e";
              string menuEingabe_eigenebewertung = "eigenebewertung";
              while (true) {
                  cout << "Du hast Games ausgewaehlt. Bitte waehle zwischen folgenden Kategorien:" << endl;
                  cout << "(n)ame" << endl;
                  cout << "(c)onsole" << endl;
                  cout << "(y)ear" << endl;
                  cout << "(p)ublisher" << endl;
                  cout << "(m)ode" << endl;
                  cout << "(g)enre" << endl;
                  cout << "(e)igenebewertung" << endl;
                  cout << "(z)urueck" << endl;
                  cout << "(h)ilfe" << endl;

                  getline(cin, inputSuche);
                    if (0==strcmp(menuEingabe_n.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_name.c_str(), inputSuche.c_str())) {
                        cout << "Gib einen Suchnamen fuer ein Game ein!" << endl;
                        cout << "Achtung: case sensitive!" << endl;
                        cout << "------------------------------------" << endl;
                        getline(cin, gameSuche);
                        cout << "Es wird nach folgendem Namen in Games gesucht: \'" +gameSuche + "\'" << endl;
                        bool nixGefunden=true;
                        for(unsigned i = 0; i <= (sizeof(Game)/sizeof(gameList)); i++) {
                             if (std::string::npos!=gameList[i].gamename.find(gameSuche)) {
                                    cout << gameList[i].gamename << endl;
                                  nixGefunden=false;
                             }
                        }
                        //sizeof(array) / sizeof(array[0])
                        if (nixGefunden) {
                            cout << "------------------------------------" << endl;
                            cout << "Leider nix gefunden." << endl;
                        }
                    }
                    if (0==strcmp(menuEingabe_c.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_console.c_str(), inputSuche.c_str())) {
                        cout << "Gib einen Suchnamen fuer eine Konsole ein!" << endl;
                        cout << "Achtung: case sensitive!" << endl;
                        cout << "------------------------------------" << endl;
                        getline(cin, gameSuche);
                        cout << "Es wird nach folgendem Begriff in Games-Konsolen gesucht: \'" +gameSuche + "\'" << endl;
                        bool nixGefunden=true;
                        for(unsigned i = 0; i <= (sizeof(Game)/sizeof(gameList)); i++) {
                             if (std::string::npos!=gameList[i].gameconsole.find(gameSuche)) {
                                    cout << gameList[i].gamename + ", " + gameList[i].gameconsole<< endl;
                                  nixGefunden=false;
                             }
                        }
                        if (nixGefunden) {
                            cout << "------------------------------------" << endl;
                            cout << "Leider nix gefunden." << endl;
                        }
                    }
                    if (0==strcmp(menuEingabe_y.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_year.c_str(), inputSuche.c_str())) {
                        cout << "Gib eine Jahreszahl fuer ein Game ein!" << endl;
                        cout << "Achtung: case sensitive!" << endl;
                        cout << "------------------------------------" << endl;
                        getline(cin, gameSuche);
                        cout << "Es wird nach folgendem Jahr in Games gesucht: \'" +gameSuche + "\'" << endl;
                        bool nixGefunden=true;
                        for(unsigned i = 0; i <= (sizeof(Game)/sizeof(gameList)); i++) {
                             if (std::string::npos!=gameList[i].gameyear.find(gameSuche)) {
                                    cout << gameList[i].gamename + ", " + gameList[i].gameyear << endl;
                                  nixGefunden=false;
                             }
                        }
                        if (nixGefunden) {
                            cout << "------------------------------------" << endl;
                            cout << "Leider nix gefunden." << endl;
                        }
                    }
                    if (0==strcmp(menuEingabe_p.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_publisher.c_str(), inputSuche.c_str())) {
                        cout << "Gib einen Suchnamen fuer einen Publisher ein!" << endl;
                        cout << "Achtung: case sensitive!" << endl;
                        cout << "------------------------------------" << endl;
                        getline(cin, gameSuche);
                        cout << "Es wird nach folgendem Begriff in Games gesucht: \'" +gameSuche + "\'" << endl;
                        bool nixGefunden=true;
                        for(unsigned i = 0; i <= (sizeof(Game)/sizeof(gameList)); i++) {
                             if (std::string::npos!=gameList[i].gamepublisher.find(gameSuche)) {
                                    cout << gameList[i].gamename + ", " + gameList[i].gamepublisher << endl;
                                  nixGefunden=false;
                             }
                        }
                        if (nixGefunden) {
                            cout << "------------------------------------" << endl;
                            cout << "Leider nix gefunden." << endl;
                        }
                    }
                    if (0==strcmp(menuEingabe_m.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_mode.c_str(), inputSuche.c_str())) {
                        cout << "Gib einen Suchbegriff fuer einen Spielmodus ein!" << endl;
                        cout << "Achtung: case sensitive!" << endl;
                        cout << "------------------------------------" << endl;
                        getline(cin, gameSuche);
                        cout << "Es wird nach folgendem Begriff in Games gesucht: \'" +gameSuche + "\'" << endl;
                        bool nixGefunden=true;
                        for(unsigned i = 0; i <= (sizeof(Game)/sizeof(gameList)); i++) {
                             if (std::string::npos!=gameList[i].gamemode.find(gameSuche)) {
                                    cout << gameList[i].gamename + ", " + gameList[i].gamemode << endl;
                                  nixGefunden=false;
                             }
                        }
                        if (nixGefunden) {
                            cout << "------------------------------------" << endl;
                            cout << "Leider nix gefunden." << endl;
                        }
                    }
                    if (0==strcmp(menuEingabe_g.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_genre.c_str(), inputSuche.c_str())) {
                        cout << "Gib einen Suchbegriff fuer ein Genre ein!" << endl;
                        cout << "Achtung: case sensitive!" << endl;
                        cout << "------------------------------------" << endl;
                        getline(cin, gameSuche);
                        cout << "Es wird nach folgendem Begriff in Games gesucht: \'" +gameSuche + "\'" << endl;
                        bool nixGefunden=true;
                        for(unsigned i = 0; i <= (sizeof(Game)/sizeof(gameList)); i++) {
                             if (std::string::npos!=gameList[i].gamegenre.find(gameSuche)) {
                                    cout << gameList[i].gamename + ", " + gameList[i].gamegenre << endl;
                                  nixGefunden=false;
                             }
                        }
                        if (nixGefunden) {
                            cout << "------------------------------------" << endl;
                            cout << "Leider nix gefunden." << endl;
                        }
                    }
                    //
                    if (0==strcmp(menuEingabe_e.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_eigenebewertung.c_str(), inputSuche.c_str())) {
                        cout << "Gib eine Zahl fuer eine Bewertung ein (1-10)!" << endl;
                        cout << "Achtung: case sensitive!" << endl;
                        cout << "------------------------------------" << endl;
                        getline(cin, gameSuche);
                        cout << "Es wird nach folgendem Begriff in Games gesucht: \'" +gameSuche + "\'" << endl;
                        bool nixGefunden=true;
                        for(unsigned i = 0; i <= (sizeof(Game)/sizeof(gameList)); i++) {
                             if (std::string::npos!=gameList[i].eigenebewertung.find(gameSuche)) {
                                    cout << gameList[i].gamename + ", " + gameList[i].eigenebewertung << endl;
                                  nixGefunden=false;
                             }
                        }
                        if (nixGefunden) {
                            cout << "------------------------------------" << endl;
                            cout << "Leider nix gefunden." << endl;
                        }
                      }
                    // zurueck
                    if (0==strcmp(menuEingabe_z.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_zurueck.c_str(), inputSuche.c_str())) {
                        break;
                    }
                    // hilfe
                    if (0==strcmp(menuEingabe_h.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), inputSuche.c_str())) {
                        cout << "------------------------------------" << endl;
                        cout << "Gib den in Klammern stehenden Buchstaben oder das Wort an!" << endl;
                        cout << "Beispiel: (g)enre suchen" << endl;
                        cout << "Hier gibst Du g oder genre ein." << endl;
                        cout << "------------------------------------" << endl;
                    }
              }

              suchMenuAusgabe();
          }
          // console
          if (0==strcmp(menuEingabe_c.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_console.c_str(), inputSuche.c_str())) {
              cout << "here we are" << endl;

              // deklarieren der vergleichsparameter
              // name
              string menuEingabe_n = "n";
              string menuEingabe_name = "name";
              // publisher
              string menuEingabe_p = "p";
              string menuEingabe_publisher = "publisher";
              // type
              string menuEingabe_t = "t";
              string menuEingabe_type = "type";
              // year
              string menuEingabe_y = "y";
              string menuEingabe_year = "year";

              while (true) {
                  cout << "Du hast Konsolen ausgewaehlt. Bitte waehle zwischen folgenden Kategorien:" << endl;
                  cout << "(n)ame" << endl;
                  cout << "(p)ublisher" << endl;
                  cout << "(t)ype" << endl;
                  cout << "(y)ear" << endl;
                  cout << "(z)urueck" << endl;
                  cout << "(h)ilfe" << endl;

                  getline(cin, inputSuche);
                  // suche nach name
                  if (0==strcmp(menuEingabe_n.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_name.c_str(), inputSuche.c_str())) {
                      cout << "Gib einen Suchnamen fuer eine Konsole ein!" << endl;
                      cout << "Achtung: case sensitive!" << endl;
                      cout << "------------------------------------" << endl;
                      getline(cin, consoleSuche);
                      cout << "Es wird nach folgendem Namen in Konsolen gesucht: \'" +consoleSuche + "\'" << endl;
                      bool nixGefunden=true;
                      for(unsigned i = 0; i <= (sizeof(Console)/sizeof(consoleList)); i++) {
                           if (std::string::npos!=consoleList[i].console_name.find(consoleSuche)) {
                                  cout << consoleList[i].console_name << endl;
                                nixGefunden=false;
                           }
                      }
                      if (nixGefunden) {
                          cout << "------------------------------------" << endl;
                          cout << "Leider nix gefunden." << endl;
                      }
                  }
                  // suche nach publisher
                  if (0==strcmp(menuEingabe_p.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_publisher.c_str(), inputSuche.c_str())) {
                      cout << "Gib einen Suchnamen fuer einen Publisher ein!" << endl;
                      cout << "Achtung: case sensitive!" << endl;
                      cout << "------------------------------------" << endl;
                      getline(cin, consoleSuche);
                      cout << "Es wird nach folgendem Namen in Publisher gesucht: \'" +consoleSuche + "\'" << endl;
                      bool nixGefunden=true;
                      for(unsigned i = 0; i <= (sizeof(Console)/sizeof(consoleList)); i++) {
                           if (std::string::npos!=consoleList[i].console_publisher.find(consoleSuche)) {
                                  cout << consoleList[i].console_publisher + ", " + consoleList[i].console_name << endl;
                                nixGefunden=false;
                           }
                      }
                      if (nixGefunden) {
                          cout << "------------------------------------" << endl;
                          cout << "Leider nix gefunden." << endl;
                      }
                  }
                  // suche nach type
                  if (0==strcmp(menuEingabe_t.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_type.c_str(), inputSuche.c_str())) {
                      cout << "Gib einen Suchnamen fuer einen Konsolentyp ein!" << endl;
                      cout << "Achtung: case sensitive!" << endl;
                      cout << "------------------------------------" << endl;
                      getline(cin, consoleSuche);
                      cout << "Es wird nach folgendem Namen in Typ gesucht: \'" +consoleSuche + "\'" << endl;
                      bool nixGefunden=true;
                      for(unsigned i = 0; i <= (sizeof(Console)/sizeof(consoleList)); i++) {
                           if (std::string::npos!=consoleList[i].console_type.find(consoleSuche)) {
                                  cout << consoleList[i].console_type + ", " + consoleList[i].console_name << endl;
                                nixGefunden=false;
                           }
                      }
                      if (nixGefunden) {
                          cout << "------------------------------------" << endl;
                          cout << "Leider nix gefunden." << endl;
                      }
                  }
                  // suche nach year
                  if (0==strcmp(menuEingabe_y.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_year.c_str(), inputSuche.c_str())) {
                      cout << "Gib eine Jahreszahl fuer eine Konsole ein!" << endl;
                      cout << "------------------------------------" << endl;
                      getline(cin, consoleSuche);
                      cout << "Es wird nach folgendem Jahr in Konsolen gesucht: \'" +consoleSuche + "\'" << endl;
                      bool nixGefunden=true;
                      for(unsigned i = 0; i <= (sizeof(Console)/sizeof(consoleList)); i++) {
                           if (std::string::npos!=consoleList[i].console_year.find(consoleSuche)) {
                                  cout << consoleList[i].console_year + ", " + consoleList[i].console_name << endl;
                                nixGefunden=false;
                           }
                      }
                      if (nixGefunden) {
                          cout << "------------------------------------" << endl;
                          cout << "Leider nix gefunden." << endl;
                      }
                  }
                  // zurueck
                  if (0==strcmp(menuEingabe_z.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_zurueck.c_str(), inputSuche.c_str())) {
                      break;
                  }
                  // hilfe
                  if (0==strcmp(menuEingabe_h.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), inputSuche.c_str())) {
                      cout << "------------------------------------" << endl;
                      cout << "Gib den in Klammern stehenden Buchstaben oder das Wort an!" << endl;
                      cout << "Beispiel: (n)ame suchen" << endl;
                      cout << "Hier gibst Du n oder name ein." << endl;
                      cout << "------------------------------------" << endl;
                  }
              }
          }
            // zurueck
            if (0==strcmp(menuEingabe_z.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_zurueck.c_str(), inputSuche.c_str())) {
                break;
            }
            // hilfe
            if (0==strcmp(menuEingabe_h.c_str(), inputSuche.c_str()) || 0==strcmp(menuEingabe_hilfe.c_str(), inputSuche.c_str())) {
                cout << "------------------------------------" << endl;
                cout << "Gib den in Klammern stehenden Buchstaben oder das Wort an!" << endl;
                cout << "Beispiel: (g)ames suchen" << endl;
                cout << "Hier gibst Du g oder games ein." << endl;
                cout << "------------------------------------" << endl;
            }
            suchMenuAusgabe();
    }
}

// suchmenu
void Menu::suchMenuAusgabe(){
    cout << "------------------------------------" << endl;
    cout << "Wonach moechtest du suchen?" << endl;
    cout << "(g)ames suchen" << endl;
    cout << "(c)onsoles suchen" << endl;
    cout << "(z)urueck" << endl;
    cout << "(h)ilfe" << endl;
    cout << "------------------------------------" << endl;
}

// startmenu
void Menu::startMenuAusgabe(){
    cout << "------------------------------------" << endl;
    cout << "Was moechtest du machen?" << endl;
    cout << "(s)uche" << endl;
    cout << "(e)xport to converted xml file" << endl;
    cout << "(h)ilfe" << endl;
    cout << "(b)eenden" << endl;
    cout << "------------------------------------" << endl;
}

// konvertieren
// vorgabe des xml-ausgabeformats
void Menu::convert(Console consoleList[], Game gameList[]){
    cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    cout << "<collection>" << endl;
    for (unsigned i = 0; i <= (sizeof(Console)/sizeof(consoleList)); i++) {
        if (consoleList[i].console_name.empty()) {
            break;
        }
        cout << "   <console id=\"" + consoleList[i].id + "\">" << endl;
        cout << "       <console_name attribut1=\"" + consoleList[i].attribut1 + "\" attribut2=\"" + consoleList[i].attribut2 + "\">" + consoleList[i].console_name + "</console_name>" << endl;
        cout << "       <console_publisher>" + consoleList[i].console_publisher + "</console_publisher>" << endl;
        cout << "       <console_year>" + consoleList[i].console_year + "</console_year>" << endl;
        cout << "       <console_type>" + consoleList[i].console_type + "</console_type>" << endl;
        for(unsigned j = 0; j <= (sizeof(Game)/sizeof(gameList)); j++) {
             if (0==strcmp(consoleList[i].console_name.c_str(), gameList[j].gameconsole.c_str())) {
                    cout << "    <game>" << endl;
                    cout << "        <gamename>" + gameList[j].gamename + "</gamename>" << endl;
                    cout << "        <gameyear>" + gameList[j].gameyear + "</gameyear>" << endl;
                    cout << "        <gamepublisher>" + gameList[j].gamepublisher + "</gamepublisher>" << endl;
                    cout << "        <gamemode>" + gameList[j].gamemode + "</gamemode>" << endl;
                    cout << "        <gamegenre>" + gameList[j].gamegenre + "</gamegenre>" << endl;
                    cout << "        <eigenebewertung>" + gameList[j].eigenebewertung + "</eigenebewertung>" << endl;
                    cout << "    </game>" << endl;
             }
        }
        cout << "   </console>" << endl;
    }
    cout << "</collection>" << endl;
}
