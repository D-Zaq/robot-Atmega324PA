#include "moteurDroit.h"

/**
 * Changer la vitesse de la roue Droite ainsi que la direction
 * @param vitesse       la nouvelle vitesse de la roue
 *                      (negatif pour reculer)
*/
void changementVitesseDroite(int vitesse)
{
    if (vitesse < 0)
    {
        ajustementPWMDroite(-1 * vitesse);
        allumerDelDroiteRouge();
    }
    else
    {
        ajustementPWMDroite(vitesse);
        allumerDelDroiteVert();
    }
}

/**
 * Changer la vitesse de la roue Droite graduellement (en accelerant)
 * @param vitesseIni    la vitesse initial de la roue
 * @param vitesseFin    la vitesse final de la roue
 * @param autreRoue     la vitesse de la roue Gauche (constante)
 * @param vitesseDif    le taux avec lequelle la roue va tourner  
 * @param attenteMs     le temps qu'on va attendre une fois que la vitesse
 *                      final est atteindre (en Ms)                
*/
void accelerationDroite(int vitesseIni,
                        int vitesseFin, int autreRoue, int vitesseDif,
                        int attenteMs)
{
    int i = 0;
    int vitesseRobot = vitesseIni;
    while (vitesseRobot != vitesseFin)
    {
        i = 0;

        ajustementPWMDroite(vitesseRobot);
        do
        {
            i++;
            afficherChiffreDansSegment(autreRoue, vitesseRobot);
        } while (i < 2);
        if (vitesseRobot < 0)
        {

            vitesseRobot -= vitesseDif;
            allumerDelGaucheRouge();
        }
        else
        {
            vitesseRobot += vitesseDif;
            allumerDelDroiteVert();
        }
    }
    i = 0;
    do
    {
        afficherChiffreDansSegment(autreRoue, vitesseRobot);
        i++;
    } while (i < attenteMs / 50);
}

/**
 * Changer la vitesse de la roue Droite graduellement (en ralentissant)
 * @param vitesseIni    la vitesse initial de la roue
 * @param vitesseFin    la vitesse final de la roue
 * @param autreRoue     la vitesse de la roue Gauche (constante)
 * @param vitesseDif    le taux avec lequelle la roue va tourner  
 * @param attenteMs     le temps qu'on va attendre une fois que la vitesse
 *                      final est atteindre (en Ms)                
*/
void ralentissementDroite(int vitesseIni,
                          int vitesseFin, int autreRoue, int vitesseDif,
                          int attenteMs)
{
    int i = 0;
    int vitesseRobot = vitesseIni;

    while (vitesseRobot != vitesseFin)
    {
        ajustementPWMDroite(vitesseRobot);
        i = 0;
        do
        {
            i++;
            afficherChiffreDansSegment(autreRoue, vitesseRobot);
        } while (i < 2);

        if (vitesseRobot < 0)
        {
            vitesseRobot += vitesseDif;
            allumerDelDroiteRouge();
        }
        else
        {
            vitesseRobot -= vitesseDif;
            allumerDelDroiteVert();
        }
    }
    i = 0;
    do
    {
        afficherChiffreDansSegment(autreRoue, vitesseRobot);
        i++;
    } while (i < attenteMs / 50);
}


