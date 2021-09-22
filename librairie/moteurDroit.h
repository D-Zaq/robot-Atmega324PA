#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "allumerDel.h"
#include "signalPWM.h"
#include "afficherChiffreDansSegment.h"

void changementVitesseDroite(int vitesse);
void accelerationDroite(int vitesseIni,
                        int vitesseFin, int autreRoue, int vitesseDif,
                        int attenteMs);
void ralentissementDroite(int vitesseIni,
                          int vitesseFin, int autreRoue, int vitesseDif,
                          int attenteMs);

