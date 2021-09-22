#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <moteurDroit.h>
#include <moteurGauche.h>
#include <signalPWM.h>
#include <afficherChiffreDansSegment.h>
#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"
#include <moteurs.h>

void manoeuvre1();
void manoeuvre2();
void manoeuvre3();
void manoeuvre4();
void manoeuvre5();
void manoeuvre6();
int getManoeuvre(int indicationG, int indicationM, int indicationD);
