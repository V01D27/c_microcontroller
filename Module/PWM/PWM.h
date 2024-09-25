/*
 * PWM.h
 *
 * Created: 18.09.2024 10:53:53
 *  Author: admin
 */ 


#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>

void fast_PWM_init();

void PWM_set_duty(float prozent);



#endif /* PWM_H_ */