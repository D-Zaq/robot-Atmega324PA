#include "manoeuvre.h"

// variable global pour l'ecran LCD
LCM disp2(&DDRB, &PORTB);

/**
 * Preprogrammation de la manoeuvre 1 de notre robot
*/
void manoeuvre1()
{
    disp2.write("manoeuvre 1",0,true);
    changementVitesseGauche(90);
    changementVitesseDroite(90);
    ralentissementGauche(90, 52, 90, 1, 1000);
    accelerationGauche(52, 90, 90, 1, 2000);
    
    ajustementPWMGauche(0);
    ajustementPWMDroite(0);
    PORTC = 0x00;
}

/**
 * Preprogrammation de la manoeuvre 2 de notre robot
*/
void manoeuvre2()
{
    disp2.write("manoeuvre 2",0,true);
    changementVitesseGauche(90);
    changementVitesseDroite(90);
    ralentissementDroite(90, 52, 90, 1, 1000);
    accelerationDroite(52, 90, 90, 1, 2000);
    
    ajustementPWMGauche(0);
    ajustementPWMDroite(0);
    PORTC = 0x00;
}

/**
 * Preprogrammation de la manoeuvre 3 de notre robot
*/
void manoeuvre3()
{
    int i=0;
    disp2.write("manoeuvre 3",0,true);
    changementVitesseGauche(-50);
    changementVitesseDroite(50);
    do{
        i++;
        afficherChiffreDansSegment(-50, 50);
    }while(i< 20);
    i=0;
    changementVitesseGauche(66);
    changementVitesseDroite(66);
    do{
        i++;
        afficherChiffreDansSegment(66, 66);
    }while(i< 40);
    i=0;
    changementVitesseGauche(50);
    changementVitesseDroite(-50);
    do{
        i++;
        afficherChiffreDansSegment(50, -50);
    }while(i< 20);
    i=0;
    changementVitesseGauche(78);
    changementVitesseDroite(78);
    do{
        i++;
        afficherChiffreDansSegment(78, 78);
    }while(i< 40);
   
    ajustementPWMGauche(0);
    ajustementPWMDroite(0);
    PORTC = 0x00;
}

/**
 * Preprogrammation de la manoeuvre 4 de notre robot
*/
void manoeuvre4()
{
    int i=0;
    disp2.write("manoeuvre 4",0,true);
    changementVitesseGauche(50);
    changementVitesseDroite(-50);
    do{
        i++;
        afficherChiffreDansSegment(50, -50);
    }while(i< 20);
    i=0;
    changementVitesseGauche(66);
    changementVitesseDroite(66);
    do{
        i++;
        afficherChiffreDansSegment(66, 66);
    }while(i< 40);
    i=0;
    changementVitesseGauche(-50);
    changementVitesseDroite(50);
    do{
        i++;
        afficherChiffreDansSegment(-50, 50);
    }while(i< 20);
    i=0;
    changementVitesseGauche(78);
    changementVitesseDroite(78);
    do{
        i++;
        afficherChiffreDansSegment(78, 78);
    }while(i< 40);
    i=0;
    disp2.write("fin de la manoeuvre 4",0,true);
    
    ajustementPWMGauche(0);
    ajustementPWMDroite(0);
    PORTC = 0x00;
}

/**
 * Preprogrammation de la manoeuvre 5 de notre robot
*/
void manoeuvre5()
{
    int i=0;
    disp2.write("manoeuvre 5",0,true);
    changementVitesseGauche(50);
    changementVitesseDroite(-50);
    do{
        i++;
        afficherChiffreDansSegment(50, -50);
    }while(i< 40);
    i=0;
    changementVitesseGauche(0);
    changementVitesseDroite(0);

    accelerationDeuxRoues(0,63,3,2000);
    
    i=0;
    
    ajustementPWMGauche(0);
    ajustementPWMDroite(0);
    PORTC = 0x00;
}

/**
 * Preprogrammation de la manoeuvre 6 de notre robot
*/
void manoeuvre6()
{
    disp2.write("manoeuvre 6",0,true);
    changementVitesseGauche(90);
    changementVitesseDroite(90);
    /// les deux roues ///
    ralentissementDeuxRoues(90,41,7,2000);
    
    ajustementPWMGauche(0);
    ajustementPWMDroite(0);
    PORTC = 0x00;
    
}

/**
 * Retourne la bonne manoeuvre selon la distance des obstacles
 * par categorie 
 * Moins de 1 mètre : 1
 * Un mètre ou plus, mais moins de 3 mètres : 2
 * 3 mètres ou plus : 3
 * @param indicationG       categorie d'obstacle a gauche
 * @param indicationM       categorie d'obstacle au milieu
 * @param indicationD       categorie d'obstacle a droite
 * @return  la manoeuvre a effectuer
*/
int getManoeuvre(int indicationG, int indicationM, int indicationD)
{
    if(indicationG == 3 && indicationM == 3 && indicationD == 2){
        return 1;
    }
    if(indicationG == 2 && indicationM == 3 && indicationD == 3){
        return 2;
    }
    if(indicationG == 3 && indicationM == 1 && indicationD == 1){
        return 3;
    }
    if(indicationG == 1 && indicationM == 1 && indicationD == 3){
        return 4;
    }
    if(indicationG == 1 && indicationM == 1 && indicationD == 1){
        return 5;
    }
    if(indicationG == 2 && indicationM == 3 && indicationD == 2){
        return 6;
    }
    return 7;
}