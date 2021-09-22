#include "afficherChiffreDansSegment.h"


/**
 * Methode qui active le bon afficheur en 
 * modifiant le Port A
 * @param segment       le segment a active
*/
void choisirSegment(uint8_t segment)
{
	switch(segment)
	{      
                case 1:
                        PORTA |= 0xf8;
        		PORTA &= 0xF7; // afficher dans le premier segment
                        break;
                case 2:
                        PORTA |= 0xf8;
        		PORTA &= 0xEF; // afficher dans le deusieme segment
                        break;        
                case 3:
                        PORTA |= 0xf8;
       			PORTA &= 0xDF; // afficher dans le troisieme segment
                        break;
		case 4:
                        PORTA |= 0xf8;
        		PORTA &= 0xBF; // afficher dans le quatrieme segment
                        break;        
                case 5:
                        PORTA |= 0xf8;
       			PORTA &= 0x7F; // afficher dans le cinquieme segment
                        break;
	}
}

/**
 * Methode qui affiche le bon chiffre en 
 * modifiant le Port C
 * @param chiffre       le chiffre a ecrire
*/
void afficherChiffre(uint8_t chiffre)
{
	switch(chiffre)
	{
		case 0:
                        PORTC=0xFC;
                        break;        
                case 1:
                        PORTC=0x60;
                        break;
                case 2:
                        PORTC=0xDA;
                        break;        
                case 3:
                        PORTC=0xF2;
                        break;
		case 4:
                        PORTC=0x66;
                        break;        
                case 5:
                        PORTC=0xB6;
                        break;
		case 6:
                        PORTC=0xBE;
                        break;        
                case 7:
                        PORTC=0xE0;
                        break;
		case 8:
                        PORTC=0xFE;
                        break;        
                case 9:
                        PORTC=0xF6;
                        break;
		default:
			PORTC=0x02;
			break;
	}
}

/**
 * Methode qui affiche les bons chiffres 
 * dans l'afficheur 7-segment
 * \param chiffre1      le chiffre qui sera ecrit a gauche
 * \param chiffre2      le chiffre qui sera ecrit a droite
*/
void afficherChiffreDansSegment(int8_t chiffre1, int8_t chiffre2)
{
        const uint8_t BARRE = -1;
        if(chiffre1 < 0)
                chiffre1 = -1*chiffre1;
        if(chiffre2 < 0)
                chiffre2 = -1*chiffre2;
            
        uint8_t s1 = chiffre1/10;
        uint8_t s2 = chiffre1 % 10;
        uint8_t s4 = chiffre2/10;
        uint8_t s5 = chiffre2 % 10;

        uint16_t const DELAI = 10;

        choisirSegment(1); 
        afficherChiffre(s1); 
        delayMs(DELAI);

        choisirSegment(2);
        afficherChiffre(s2); 
        delayMs(DELAI);

        choisirSegment(3);
        afficherChiffre(BARRE); 
        delayMs(DELAI);

        choisirSegment(4);
        afficherChiffre(s4);
        delayMs(DELAI);

        choisirSegment(5);
        afficherChiffre(s5); 
        delayMs(DELAI);

}





