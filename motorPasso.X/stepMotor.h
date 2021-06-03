#ifndef STEPMOTOR_H
#define STEPMOTOR_H

#define SENTIDO_HORARIO        1
#define ANTI_HORARIO          -1
#define MEIO_PASSO             1 
#define PASSO                  0
#define LED_VERMELHO           PORTDbits.RD4
#define LED_VERDE              PORTDbits.RD5

void stepMotor_init ( int passos );
void stepMotor ( char step, char sense, int graus, int t);

#endif
