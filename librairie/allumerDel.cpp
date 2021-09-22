#define F_CPU 8000000
#include "allumerDel.h"

/**
 * Methode qui allume la Del Droite en vert 
 * en controlant le Port D
*/
void allumerDelDroiteVert()
{
    PORTD &= 0x7B;
    PORTD |= 0x04;
}

/**
 * Methode qui allume la Del Droite en rouge 
 * en controlant le Port D
*/
void allumerDelDroiteRouge()
{
    PORTD &= 0x7B;
    PORTD |= 0x80;
}

/**
 * Methode qui allume la Del Gauche en vert 
 * en controlant le Port D
*/
void allumerDelGaucheVert()
{
    PORTD &= 0xFC;
    PORTD |= 0x01;
}

/**
 * Methode qui allume la Del Gauche en rouge 
 * en controlant le Port D
*/
void allumerDelGaucheRouge()
{
    PORTD &= 0xFC;
    PORTD |= 0x02;
}
