#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>
#include <AFMotor.h>

// Motor channel instances (M1 - M4 on Adafruit Motor Shield v1)
static AF_DCMotor m1(1);
static AF_DCMotor m2(2);
static AF_DCMotor m3(3);
static AF_DCMotor m4(4);

static AF_DCMotor* motors[4] = {&m1, &m2, &m3, &m4};

// PWM speed presets (0 - 255)
const uint8_t SPEED_SLOW   = 40;
const uint8_t SPEED_NORMAL = 70;
const uint8_t SPEED_FAST   = 110;

// Set PWM speed for a specific channel (1-4) or all channels (0)
inline void set_motors(uint8_t motor_id, uint8_t pwm) {
  if (motor_id == 0) {
    for (uint8_t i = 0; i < 4; i++) {
      motors[i]->setSpeed(pwm);
    }
  } else if (motor_id >= 1 && motor_id <= 4) {
    motors[motor_id - 1]->setSpeed(pwm);
  }
}

// Apply run states to all four channels simultaneously
inline void applyDirections(uint8_t m1_dir, uint8_t m2_dir, uint8_t m3_dir, uint8_t m4_dir) {
  motors[0]->run(m1_dir);
  motors[1]->run(m2_dir);
  motors[2]->run(m3_dir);
  motors[3]->run(m4_dir);
}

inline void driveForward()  { applyDirections(FORWARD,  FORWARD,  FORWARD,  FORWARD);  }
inline void driveBackward() { applyDirections(BACKWARD, BACKWARD, BACKWARD, BACKWARD); }
inline void turnLeft()      { applyDirections(BACKWARD, BACKWARD, FORWARD,  FORWARD);  }
inline void turnRight()     { applyDirections(FORWARD,  FORWARD,  BACKWARD, BACKWARD); }
inline void stopMotors()    { applyDirections(RELEASE,   RELEASE,   RELEASE,   RELEASE);   }

// Initialize motors to default cruise speed and stopped state
inline void setup_motors() {
  set_motors(0, SPEED_NORMAL);
  stopMotors();
}

#endif // MOTORS_H
