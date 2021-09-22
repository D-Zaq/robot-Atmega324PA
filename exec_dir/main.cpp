/**
 * file : main.cpp
 * 
 * date : 17/04/2020
 * 
 * auteurs :
 * Lotfi Fodil
 * Zakaria Diabi
 * Mohamed Issam Berrahil
 * Gaya Bessaih
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h> /* Include LCD header file */
#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"
#include <afficherChiffreDansSegment.h>
#include <delayMs.h>
#include <initInterruption.h>
#include <moteurGauche.h>
#include <moteurDroit.h>
#include <moteurs.h>
#include <manoeuvre.h>
#include <signalPWM.h>
#include <sonar.h>


#define DEMO_DDR DDRB   // `Data Direction Register' AVR occupé par l'aff.
#define DEMO_PORT PORTB // Port AVR occupé par l'afficheur
int indicationG = 0;
int indicationM = 0;
int indicationD = 0;
int volatile counterG = 0;
int volatile counterM = 0;
int volatile counterD = 0;

LCM disp(&DEMO_DDR, &DEMO_PORT);
int volatile minuterieExpiree;
bool volatile clique = false;

void static inline w(void)
{
    _delay_ms(600);
}


ISR(INT1_vect)
{
    clique = true;
}

int main()
{

    DDRD = 0xF7;
    DDRA = 0xf8;
    DDRC = 0xff;
    int manoeuvre;
    initialisation();

    while (1)
    {
        // on etaint les oscilloscopes, les DEL et les
        //afficheurs 7 segments
        PORTA |= 0xF8;
        PORTC |= 0xFF;
        PORTD = 0xFF;

        if(!clique)
        {
            // sonar //
            cli();
            envSignal();
            sei();
            counterM = detecteMilieu();
            envSignal();
            counterG = detecteGauche();
            envSignal();
            counterD = detecteDroite();

            int tab[] = {counterG, counterM, counterD};
            calculerDistance(tab,indicationG,indicationM,indicationD);
            w();
        }else
        {    
            manoeuvre = getManoeuvre(indicationG, indicationM,indicationD);
            DDRA = 0xf8;
            DDRC = 0xff;
            // manoeuvre //
            switch (manoeuvre)
            {
            case 1:
                manoeuvre1();
                break;
            case 2:
                manoeuvre2();
                break;
            case 3:
                manoeuvre3();
                break;
            case 4:
                manoeuvre4();
                break;
            case 5:
                manoeuvre5();
                break;
            case 6:
                manoeuvre6();
                break;
            case 7 :
                disp.write("Combinaison", 0,true);
                disp.write("non evaluee", 16, false);
                delayMs(2000);
            }
            clique = false;
        }
    }

    return 0;
}
