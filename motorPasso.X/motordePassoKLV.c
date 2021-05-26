/*
 * File:   motordePassoKLV.c
 * Author: 21193634
 *
 * Created on 26 de Maio de 2021, 14:03
 */


#include <xc.h>
#include "delay.h"
#include "motordePassoKLV.h"

int ppr = 16;
char passos[4] = {0x02,0x04,0x01,0x08};
char indice = 0;

void motordePasso_klv_init (int pulsosPorRevolucao )
{
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    
    PORTDbits.RD0 = 0;
    PORTDbits.RD1 = 0;
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 0;
    
    ppr = pulsosPorRevolucao;
}

void motordePassoKLV (char sentido, int graus, int t ) 
{
   int i;
   int numPassos;
   numPassos = (graus * ppr)/360;
   
   for( i=0; i<numPassos; i++ )
   {
       PORTD = ((PORTD & 0xF0) | passos[indice]);
       indice = (indice+sentido) % 4;
       delay(250);
   }
}
