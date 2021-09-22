#include <moteurs.h>

/**
 * Changer la vitesse des deux roues graduellement (en accelerant)
 * @param vitesseIni    la vitesse initial de la roue
 * @param vitesseFin    la vitesse final de la roue
 * @param vitesseDif    le taux avec lequelle la roue va tourner  
 * @param attenteMs     le temps qu'on va attendre une fois que la vitesse
 *                      final est atteindre (en Ms)                
*/
void accelerationDeuxRoues(int vitesseIni,
int vitesseFin, int vitesseDif,
int attenteMs)
{
    int i = 0;
    int vitesseRobot = vitesseIni;
    while (vitesseRobot != vitesseFin)
    {
        ajustementPWMGauche(vitesseRobot);
        ajustementPWMDroite(vitesseRobot);
        i = 0;
        do
        {
            i++;
            afficherChiffreDansSegment(vitesseRobot, vitesseRobot);
            _delay_ms(5);
        } while (i < 2);
        vitesseRobot += vitesseDif;
        allumerDelGaucheVert();
        allumerDelDroiteVert();
    }
    i = 0;
    do
    {
        afficherChiffreDansSegment(vitesseRobot, vitesseRobot);
        i++;
    } while (i < attenteMs / 50);
}

/**
 * Changer la vitesse des deux roues graduellement (en ralentissant)
 * @param vitesseIni    la vitesse initial de la roue
 * @param vitesseFin    la vitesse final de la roue
 * @param vitesseDif    le taux avec lequelle la roue va tourner  
 * @param attenteMs     le temps qu'on va attendre une fois que la vitesse
 *                      final est atteindre (en Ms)                
*/
void ralentissementDeuxRoues(int vitesseIni,
int vitesseFin, int vitesseDif,
int attenteMs)
{
    int i = 0;
    int vitesseRobot = vitesseIni;
    while (vitesseRobot != vitesseFin)
    {
        ajustementPWMGauche(vitesseRobot);
        ajustementPWMDroite(vitesseRobot);
        i = 0;
        do
        {
            i++;
            afficherChiffreDansSegment(vitesseRobot, vitesseRobot);
        } while (i < 10);
        vitesseRobot -= vitesseDif;
        allumerDelGaucheVert();
        allumerDelDroiteVert();
    }
    i = 0;
    do
    {
        afficherChiffreDansSegment(vitesseRobot, vitesseRobot);
        i++;
    } while (i < attenteMs / 50);
}