#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <delayMs.h>

void choisirSegment(uint8_t segment);
void afficherChiffre(uint8_t chiffre);
void afficherChiffreDansSegment(int8_t chiffre, int8_t chiffre2);