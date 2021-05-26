#ifndef STEPMOTOR_H
#define STEPMOTOR_H

#define CW         1
#define CCW       -1

void stepMotor_init ( int pulsosPorRevolucao );
void stepMotor ( char sentido, int graus, int t);

#endif
