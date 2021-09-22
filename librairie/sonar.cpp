#define F_CPU 8000000
#include "sonar.h"

const double DELAI = 8.75;

// variable global pour l'ecran LCD
LCM disp1(&DDRB, &PORTB);


/**
 * mettre la broche B0 a 1 ensuite a 0           
*/
void envSignal()
{
    PORTB |= (1 << PB0);
    _delay_us(10);
    PORTB &= (~(1 << PB0));
}

/**
 * retourne la distance en micro-seconde de l'obstacle a gauche
 * (retourne 0 si aucun obstacle n'a ete detecte) 
 * @return      la distance en micro-seconde         
*/
int detecteGauche()
{
    int counter = 0;
    while (!(PINA & (1 << PA0)))
    {
    }
    while ((PINA & (1 << PA0)) != 0)
    {
        counter++;
        _delay_us(DELAI);
        
        if (counter > 3600)
        {
            return 0;
        }
    }
    return counter;
}

/**
 * retourne la distance en micro-seconde de l'obstacle a droite
 * (retourne 0 si aucun obstacle n'a ete detecte) 
 * @return      la distance en micro-seconde         
*/
int detecteDroite()
{
    int counter = 0;
    while (!(PINA & (1 << PA2)))
    {
    }
    while ((PINA & (1 << PA2)) != 0)
    {
        counter++;
        _delay_us(DELAI);
        if (counter > 3600)
        {
            return 0;
        }
    }
    return counter;
}

/**
 * retourne la distance en micro-seconde de l'obstacle au milieu
 * (retourne 0 si aucun obstacle n'a ete detecte) 
 * @return      la distance en micro-seconde         
*/
int detecteMilieu()
{
    int counter = 0;
    while (!(PINA & (1 << PA1)))
    {
    }
    while ((PINA & (1 << PA1)) != 0)
    {
        counter++;
        _delay_us(DELAI);
        if (counter > 3600)
        {
            return 0;
        }
    }
    return counter;
}

/**
 * ecrit la distance sur l'ecran LCD en metre 
 * @param distance      la distance a afficher (metre)         
*/
void ecrireDistance(int distance)
{

    if (distance >= 10)
        disp1 << distance / 10;
    if (distance < 10)
        disp1 << '0';
    disp1 << '.';
    disp1 << distance % 10;
}

/**
 * on arondie le chiffre et le retourne
 * @param chiffre      le chiffre a arondir 
 * @return             le chiffre arondie       
*/
int arondie(int chiffre)
{

    if (chiffre % 100 >= 5)
        if (chiffre > 20 && chiffre < 64)
            chiffre = 69;
    return chiffre;
}

/**
 * ecrire la bonne etiquette en dessous de chaque distance
 * Moins de 1 mètre : danger (DNGR)
 * Un mètre ou plus, mais moins de 3 mètres : attention (ATTN)
 * 3 mètres ou plus : ok (OK)
 * @param tab           tableau qui contient les 3 distance en Ms
 * @param indicationG       categorie d'obstacle a gauche
 * @param indicationM       categorie d'obstacle au milieu
 * @param indicationD       categorie d'obstacle a droite         
*/
void ecrireEtiquette(int tab[], int& indicationG, int& indicationM, int& indicationD)
{
    if (tab[0] < 590){
        disp1 << "DNGR  ";
        indicationG =1;
    }
    if (tab[0] >= 590 && tab[0] < 1780){
        disp1 << "ATTN  ";
        indicationG =2;
    }
    if (tab[0] >= 1780){
        disp1 << " OK   ";
        indicationG =3;
    }

    if (tab[1] < 590){
        disp1 << "DNGR  ";
        indicationM =1;
    }

    if (tab[1] >= 590 && tab[1] < 1780){
        disp1 << "ATTN  ";
        indicationM =2;
    }
    if (tab[1] >= 1780){
        disp1 << " OK   ";
        indicationM =3;
    }

    if (tab[2] < 590){
        disp1 << "DNGR";
        indicationD =1;
    }
    if (tab[2] >= 590 && tab[2] < 1780){
        disp1 << "ATTN";
        indicationD =2;
    }
    if (tab[2] >= 1780){
        disp1 << " OK ";
        indicationD =3;
    }

}

/**
 * transformer chaque distance de Ms en CM
 * @param counter           tableau qui contient les 3 distance en Ms
 * @param indicationG       categorie d'obstacle a gauche (a modifier)
 * @param indicationM       categorie d'obstacle au milieu (a modifier)
 * @param indicationD       categorie d'obstacle a droite (a modifier)
*/
void calculerDistance(int counter[], int& indicationG, int& indicationM, int& indicationD)
{
    disp1.clear();
    int temp[] = {counter[0],counter[1],counter[2]};
    counter[0] = arondie(counter[0]);
    counter[1] = arondie(counter[1]);
    counter[2] = arondie(counter[2]);

    float distance1, distance2, distance3;
    distance1 = (counter[0] / 58.0f);
    ecrireDistance(distance1);
    disp1 << "m  ";
    distance2 = (counter[1] / 58.0f);
    ecrireDistance(distance2);
    disp1 << "m  ";
    distance3 = (counter[2] / 58.0f);
    ecrireDistance(distance3);
    disp1 << 'm';

    ecrireEtiquette(temp, indicationG, indicationM, indicationD);
    
}



