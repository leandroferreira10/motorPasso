

#include <xc.h>
#include "config.h"


void delay ( unsigned int t)
{
    while ( t )
    {
        __delay_ms( 1 );
        --t;
    }
}