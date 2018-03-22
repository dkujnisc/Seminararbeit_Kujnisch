#ifndef CONSOLE_H
#define CONSOLE_H

using namespace std;

class Console
{
    public:

        string id;
        string attribut1;
        string attribut2;
        string console_name;
        string console_publisher;
        string console_year;
        string console_type;

        bool start=false;
        bool attributFlag=false;

        int krokodilcounter=0;


        char zeichen;
        int zaehler=0;
        int element=-1;
        /* dabei gilt:
           element = 0 : console_name
           element = 1 : console_publisher
           element = 2 : console_year
           element = 3 : console_type
        */
        int attributcounter=-1;
        /* dabei gilt:
            attribut = 0 : id
            attribut = 1 : attribut1
            attribut = 2 : attribut2
        */
        int parsezeichen();
        Console getConsole();
    private:
        char puffer[100];
} ;

class Game
{
    public:
        string gamename;
        string gameconsole;
        string gameyear;
        string gamepublisher;
        string gamemode;
        string gamegenre;
        string eigenebewertung;

        bool start=false;

        int krokodilcounter=0;

        char zeichen;
        int zaehler=0;
        int element=-1;
        /* dabei gilt:
           element = 0 : gamename
           element = 1 : gameconsole
           element = 2 : gameyear
           element = 3 : gamepublisher
           element = 4 : gamemode
           element = 5 : gamegenre
           element = 6 : eigenebewertung
        */
        int parsezeichen();
        Game getGame();
    private:
        char puffer[100];
} ;

class Menu
{
    public:
        void startMenu(Console consoleList[], Game gameList[]);
        void suche(Console consoleList[], Game gameList[]);
        void suchMenuAusgabe();
        void startMenuAusgabe();
};

class Search
{
    public:

};
#endif


