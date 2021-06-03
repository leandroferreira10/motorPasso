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

void main(void)                                                // Função principal main.
{                                                              // Inicio da função Main.
    stepMotor_init (32);                                       // Configuração de inicialização.
    while ( 1 )                                                // Laço de repetição infinito.
    {                                                          // Inicio do laço de repetição
        stepMotor ( PASSO, SENTIDO_HORARIO, 90, 500);          // Passos, sentido, graus e tempo.
        delay(3000);                                           // Espera de 3000 ms = 3s.
        stepMotor ( MEIO_PASSO, SENTIDO_HORARIO , 270, 500);   // Passos, sentido, graus, tempo.
        delay(3000);                                           // Espera de 3000 ms = 3s.
        stepMotor ( PASSO, ANTI_HORARIO , 90, 500);            // Passos, sentido, graus, tempo.
        delay(3000);                                           // Espera de 3000 ms = 3s.
        stepMotor ( MEIO_PASSO, ANTI_HORARIO , 270, 500);      // Passos, sentido, graus, tempo.
        delay(3000);                                           // Espera de 3000 ms = 3s.
    }                                                          // fim do laço de repetição.
}                                                              // fim da função main.
