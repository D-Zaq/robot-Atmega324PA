#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "allumerDel.h"
#include "signalPWM.h"
#include "afficherChiffreDansSegment.h"

void accelerationDeuxRoues(int vitesseIni, int vitesseFin, int vitesseDif, int attenteMs);
void ralentissementDeuxRoues(int vitesseIni, int vitesseFin, int vitesseDif, int attenteMs);