#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "allumerDel.h"
#include "signalPWM.h"
#include "afficherChiffreDansSegment.h"

void changementVitesseGauche(int vitesse);
void accelerationGauche(int vitesseIni,
                        int vitesseFin, int autreRoue, int vitesseDif,
                        int attenteMs);
void ralentissementGauche(int vitesseIni,
int vitesseFin, int autreRoue, int vitesseDif,
int attenteMs);

