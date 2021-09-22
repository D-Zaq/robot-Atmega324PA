#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"

void envSignal();
int detecteGauche();
int detecteDroite();
int detecteMilieu();
void ecrireDistance(int i);
int arondie(int chiffre);
void ecrireEtiquette(float tab[], int& indicationG, int& indicationM, int& indicationD);
void calculerDistance(int counter[], int& indicationG, int& indicationM, int& indicationD);


