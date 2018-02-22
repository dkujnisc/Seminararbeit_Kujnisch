// console.h
#ifndef CONSOLE_H
#define CONSOLE_H

class Parser
{
    public:
        char zeichen;
        int zaehler;
        int zustand;
        /* dabei gilt:
           zustand = 0 : standardzustand
           zustand = 1 : sonderfall familienname
        */
        int parsezeichen();
    private:
        char puffer[100];
} ;

#endif
