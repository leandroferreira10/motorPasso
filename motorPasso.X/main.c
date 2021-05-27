/*
 * File:   main.c
 * Author: 20185151
 *
 * Created on 21 de Maio de 2021, 16:03
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "motordePassoKLV.h"

void main(void) 
{
    motordePasso_klv_init ( 1024 );
    delay(1000);
    
    while( 1 )
    {
        motordePassoKLV( CW, 126, 1 );
        delay(1000);
        motordePassoKLV( CW, 126, 1 );
        delay(1000);
        motordePassoKLV( CW, 126, 1 );
        delay(1000);
        motordePassoKLV( CW, 126, 1 );
        delay(1000);
        motordePassoKLV( CW, 252, 1 );
        delay(1000);
        motordePassoKLV( CW, 252, 1 );
        delay(1000);
        motordePassoKLV( CW, 504, 1 );
        delay(1000);
    }
}
