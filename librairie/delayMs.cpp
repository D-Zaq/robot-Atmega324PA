#include "delayMs.h"

/**
 * Fait passer un certain nombre de temps
 * @param duree     la duree a attendre en Ms
*/
void delayMs (uint16_t duree) 
{
    for (uint16_t i = 0; i < duree; i++) 
    {
        _delay_ms (1);
    }
}