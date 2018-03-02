#ifndef CONSOLE_H
#define CONSOLE_H

using namespace std;

class Console
{
    public:

        string console_name;
        string console_publisher;
        string console_year;
        string console_type;

        bool start=false;

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
#endif
