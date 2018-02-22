// console.h
#ifndef CONSOLE_H
#define CONSOLE_H

class Parser
{
    public:

        string console_name;
        string console_publisher;
        string console_year;
        string console_type;

        char zeichen;
        int zaehler=0;
        int zustand=0;
        /* dabei gilt:
           zustand = 0 : standardzustand
           zustand = 1 : sonderfall familienname
        */
        int parsezeichen();
    private:
        char puffer[100];
} ;

#endif

<console>
    <console_name>Gameboy</console_name>
    <console_publisher>Nintendo</console_publisher>
    <console_year>1989</console_year>
    <console_type>Handheld-Konsole</console_type>
</console>
