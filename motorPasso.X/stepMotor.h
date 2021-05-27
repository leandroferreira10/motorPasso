#ifndef STEPMOTOR_H
#define STEPMOTOR_H

#define SH               1
#define SAH             -1
#define MEIOPASSO        1 
#define PASSO            0

void stepMotor_init ( int pulsosPorRevolucao );
void stepMotor ( char passo, char sentido, int graus, int t);

#endif
