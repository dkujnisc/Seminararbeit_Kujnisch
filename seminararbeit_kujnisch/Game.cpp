#include <iostream>
#include "header.h"

using namespace std;

Game Game::getGame(){
    Game game;
    game.gamename=gamename;
    game.gameconsole=gameconsole;
    game.gameyear=gameyear;
    game.gamepublisher=gamepublisher;
    game.gamemode=gamemode;
    game.gamegenre=gamegenre;
    game.eigenebewertung=eigenebewertung;
    element=-1;
    return game;
}

int Game::parsezeichen () {
    switch(zeichen) {
        case '>':
        krokodilcounter++;
        zaehler=0;
        if (4==krokodilcounter && -1==element) {
            element++;
            krokodilcounter=0;
            start=true;
         }
        else if (2==krokodilcounter && -1!=element) {
            element++;
            krokodilcounter=0;
            start=true;
        }
        break;
        case '<':
            if (start) {
                puffer[zaehler]='\0';
                if (0==element){
                    gamename=puffer;
                }
                if (1==element){
                    gameconsole=puffer;
                }
                if (2==element){
                    gameyear=puffer;
                }
                if (3==element){
                    gamepublisher=puffer;
                }
                if (4==element){
                    gamemode=puffer;
                }
                if (5==element){
                    gamegenre=puffer;
                }
                if (6==element){
                    eigenebewertung=puffer;
                    element++;
                }
               start=false;
            }
            break;
        default:
           puffer[zaehler]=zeichen;
           zaehler++;
           break;
    }
    return 0;
}


