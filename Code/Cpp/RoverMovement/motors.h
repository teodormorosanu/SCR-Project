#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

const uint8_t SPEED_SLOW   = 40;
const uint8_t SPEED_NORMAL = 70;
const uint8_t SPEED_FAST   = 110;

void setup_motors();
void set_motors(uint8_t motor_id, uint8_t pwm);
void applyDirections(uint8_t m1_dir, uint8_t m2_dir, uint8_t m3_dir, uint8_t m4_dir);

void driveForward();
void driveBackward();
void turnLeft();
void turnRight();
void stopMotors();

#endif // MOTORS_H