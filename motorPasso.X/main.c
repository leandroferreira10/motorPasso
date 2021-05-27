/*
 * File:   main.c
 * Author: 20185151
 *
 * Created on 21 de Maio de 2021, 16:03
 */


#include <xc.h>
#include "config.h"
#include "stepMotor.h"
#include "delay.h"

void main(void) 
{
    stepMotor_init (8);
    while ( 1 )
    {
        stepMotor ( MEIOPASSO, SH, 360, 1000);
        delay(3000);
       // stepMotor ( CCW, 360, 1000);
       // delay(3000);
    }
}
