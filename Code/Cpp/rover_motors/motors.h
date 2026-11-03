#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

const uint8_t SPEED_SLOW   = 40;
const uint8_t SPEED_NORMAL = 70;
const uint8_t SPEED_FAST   = 110;

void setup_motors();
void set_motors(uint8_t motor_id, uint8_t pwm);

void drive_forward();
void drive_backward();
void turn_left();
void turn_right();
void stop_motors();

#endif // MOTORS_H