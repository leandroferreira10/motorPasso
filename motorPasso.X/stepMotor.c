#include "config.h"
#include "delay.h"
#include <xc.h>
#include "stepMotor.h"

int ppr;
char meio_passo [8] = { 0x02, 0x06, 0x04, 0x05, 0x01, 0x09, 0x08, 0x0A };
char passo      [4] = { 0X02, 0x04, 0x01, 0x08 };
char indice = 0;

void stepMotor_init ( int passos )
{
        // Configuração dos pinos.
    TRISDbits.TRISD0 = 0;  // Saida = A+
    TRISDbits.TRISD1 = 0;  // Saida = A-
    TRISDbits.TRISD2 = 0;  // Saida = B+
    TRISDbits.TRISD3 = 0;  // Saida = B-
    TRISDbits.TRISD4 = 0;  // Saida = Led vermelho
    TRISDbits.TRISD5 = 0;  // Saida = Led verde
    
        // Inicialização do estado das bobinas e dos leds.
    PORTDbits.RD0 = 0;
    PORTDbits.RD1 = 1;
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 0;
    PORTDbits.RD4 = 0;
    PORTDbits.RD5 = 0;
    
    ppr = passos; // Variavel que armazena a quantidade de passos do motor.
}

void stepMotor ( char step, char sense, int graus, int t ) // passo, sentido, graus, tempo.
{
    int x;
    int numPassos;
    if ( sense == 1)
    {
        LED_VERDE    = 0;     // Sentido Anti-Horário desligado.
        LED_VERMELHO = 1;     // Sentido horário ligado.
    }
    else
    {
        LED_VERMELHO = 0;     // Sentido horário desligado.
        LED_VERDE    = 1;     // Sentido Anti-Horário ligado.
    }
    if ( step == MEIO_PASSO  ) // meio passo.
    {
        numPassos = ( graus * ppr)/180;
        delay(300);
        for (x=0; x<numPassos; x++ )
        {
            indice = ( indice + sense) % 8; 
            PORTD = ((PORTD & 0xF0)| meio_passo [indice]);
            delay(t);
        }
        LED_VERMELHO = 0;
        LED_VERDE    = 0;
    } 
    else 
    {
        numPassos = ( graus * ppr)/360;
        delay(300);
        for (x=0; x<numPassos; x++ )
        {
            indice = ( indice + sense) % 4; 
            PORTD = ((PORTD & 0xF0)| passo [indice]);
            delay(t);
        } 
        LED_VERMELHO = 0;
        LED_VERDE    = 0;
    }
}

