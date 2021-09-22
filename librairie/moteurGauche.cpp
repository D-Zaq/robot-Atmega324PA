#include "moteurGauche.h"

/**
 * Changer la vitesse de la roue gauche ainsi que la direction
 * @param vitesse       la nouvelle vitesse de la roue
 *                      (negatif pour reculer)
*/
void changementVitesseGauche(int vitesse)
{
    if (vitesse < 0)
    {
        ajustementPWMGauche(-1 * vitesse);
        allumerDelGaucheRouge();
    }
    else
    {
        ajustementPWMGauche(vitesse);
        allumerDelGaucheVert();
    }
}

/**
 * Changer la vitesse de la roue gauche graduellement (en accelerant)
 * @param vitesseIni    la vitesse initial de la roue
 * @param vitesseFin    la vitesse final de la roue
 * @param autreRoue     la vitesse de la roue Droite (constante)
 * @param vitesseDif    le taux avec lequelle la roue va tourner  
 * @param attenteMs     le temps qu'on va attendre une fois que la vitesse
 *                      final est atteindre (en Ms)                
*/
void accelerationGauche(int vitesseIni,
                        int vitesseFin, int autreRoue, int vitesseDif,
                        int attenteMs)
{
    int i = 0;
    int vitesseRobot = vitesseIni;
    while (vitesseRobot != vitesseFin)
    {
        ajustementPWMGauche(vitesseRobot);
        i = 0;
        do
        {
            i++;
            afficherChiffreDansSegment(vitesseRobot, autreRoue);
        } while (i < 2);

        if (vitesseRobot < 0)
        {
            vitesseRobot -= vitesseDif;
            allumerDelGaucheRouge();
        }
        else
        {
            vitesseRobot += vitesseDif;
            allumerDelGaucheVert();
        }
    }
    i = 0;
    do
    {
        afficherChiffreDansSegment(vitesseRobot, autreRoue);
        i++;
    } while (i < attenteMs / 50);
}

/**
 * Changer la vitesse de la roue gauche graduellement (en ralentissant)
 * @param vitesseIni    la vitesse initial de la roue
 * @param vitesseFin    la vitesse final de la roue
 * @param autreRoue     la vitesse de la roue Droite (constante)
 * @param vitesseDif    le taux avec lequelle la roue va tourner  
 * @param attenteMs     le temps qu'on va attendre une fois que la vitesse
 *                      final est atteindre (en Ms)                
*/
void ralentissementGauche(int vitesseIni,
int vitesseFin, int autreRoue, int vitesseDif,
int attenteMs)
{
    int i = 0;
    int vitesseRobot = vitesseIni;
    while (vitesseRobot != vitesseFin)
    {
        ajustementPWMGauche(vitesseRobot);
        i = 0;
        do
        {
            i++;
            afficherChiffreDansSegment(vitesseRobot, autreRoue);
        } while (i < 2);

        if (vitesseRobot < 0)
        {
            vitesseRobot += vitesseDif;
            allumerDelGaucheRouge();
        }
        else
        {
            vitesseRobot -= vitesseDif;
            allumerDelGaucheVert();
        }
    }
    i = 0;
    do
    {
        afficherChiffreDansSegment(vitesseRobot, autreRoue);
        i++;
    } while (i < attenteMs / 50);
}

