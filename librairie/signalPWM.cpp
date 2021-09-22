#define F_CPU 8000000
#include "signalPWM.h"

/**
 * ajustement des registre              
*/
void ajustement()
{
    TCCR1A |= 1 << WGM10 | 1 << COM1A1 | 1 << COM1A0 | 1 << COM1B1 | 1 << COM1B0;
    TCCR1B |= 1 << CS11;
    TCCR1C = 0;
}

/**
 * ajustement de OCR1B (vitesse gauche)
 * @param vitesseGauche     la valeur que va prendre le registre OCR1B
 *                          (valeur en %)              
*/
void ajustementPWMGauche(int8_t vitesseGauche)
{
    if (vitesseGauche < 0)
        vitesseGauche *= -1;
    OCR1B = 255 - (255 * vitesseGauche / 100);
    ajustement();
}

/**
 * ajustement de OCR1A (vitesse droite)
 * @param vitesseDroite     la valeur que va prendre le registre OCR1A
 *                          (valeur en %)             
*/
void ajustementPWMDroite(int8_t vitesseDroite)
{
    if (vitesseDroite < 0)
        vitesseDroite *= -1;
    OCR1A = 255 - (255 * vitesseDroite / 100);
    ajustement();
}
