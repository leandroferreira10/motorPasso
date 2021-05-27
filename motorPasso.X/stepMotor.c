

#include "config.h"
#include "delay.h"
#include <xc.h>
#include "stepMotor.h"

int ppr;
char passos [8] = { 0X02, 0x06, 0x04, 0x05, 0x01, 0x09, 0x08, 0x0A };
char tabela [4] = { 0x02, 0x04, 0x01, 0x08 };
char indice = 0;

void stepMotor_init ( int pulsosPorRevolucao )
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

void stepMotor ( char passo, char sentido, int graus, int t )
{
    if ( passo == MEIOPASSO  ) // meio passo.
    {
        int x;
        int numPassos;
        numPassos = ( graus * ppr)/180;

        for (x=0; x<numPassos; x++ )
        {
            PORTD = ((PORTD & 0xF0)| passos [indice]);
            delay(t);
            indice = ( indice + sentido) % 8;  
        }
    } 
    else 
    {
        int x;
        int numPassos;
        numPassos = ( graus * ppr)/360;

        for (x=0; x<numPassos; x++ )
        {
            PORTD = ((PORTD & 0xF0)| tabela [indice]);
            delay(t);
            indice = ( indice + sentido) % 4;   
        } 
    }
}

