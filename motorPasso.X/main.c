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

void main(void)                                                // Fun��o principal main.
{                                                              // Inicio da fun��o Main.
    stepMotor_init (32);                                       // Configura��o de inicializa��o.
    while ( 1 )                                                // La�o de repeti��o infinito.
    {                                                          // Inicio do la�o de repeti��o
        stepMotor ( PASSO, SENTIDO_HORARIO, 90, 500);          // Passos, sentido, graus e tempo.
        delay(3000);                                           // Espera de 3000 ms = 3s.
        stepMotor ( MEIO_PASSO, SENTIDO_HORARIO , 270, 500);   // Passos, sentido, graus, tempo.
        delay(3000);                                           // Espera de 3000 ms = 3s.
        stepMotor ( PASSO, ANTI_HORARIO , 90, 500);            // Passos, sentido, graus, tempo.
        delay(3000);                                           // Espera de 3000 ms = 3s.
        stepMotor ( MEIO_PASSO, ANTI_HORARIO , 270, 500);      // Passos, sentido, graus, tempo.
        delay(3000);                                           // Espera de 3000 ms = 3s.
    }                                                          // fim do la�o de repeti��o.
}                                                              // fim da fun��o main.
