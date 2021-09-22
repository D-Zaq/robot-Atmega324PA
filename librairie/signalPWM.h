#define F_CPU 8000000
#include <avr/io.h>

void ajustement();
void ajustementPWMGauche(int8_t vitesseGauche);
void ajustementPWMDroite(int8_t vitesseDroite);
