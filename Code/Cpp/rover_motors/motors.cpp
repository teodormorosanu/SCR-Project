#include "motors.h"
#include <AFMotor.h>

// Instante hardware interne pentru canalele shield-ului Adafruit v1
static AF_DCMotor m1(1);
static AF_DCMotor m2(2);
static AF_DCMotor m3(3);
static AF_DCMotor m4(4);

static AF_DCMotor* motors[4] = {&m1, &m2, &m3, &m4};

void set_motors(uint8_t motor_id, uint8_t pwm) {
  if (motor_id == 0) {
    for (uint8_t i = 0; i < 4; i++) {
      motors[i]->set_speed(pwm);
    }
  } else if (motor_id >= 1 && motor_id <= 4) {
    motors[motor_id - 1]->set_speed(pwm);
  }
}

static void apply_directions(uint8_t m1_dir, uint8_t m2_dir, uint8_t m3_dir, uint8_t m4_dir) {
  motors[0]->run(m1_dir);
  motors[1]->run(m2_dir);
  motors[2]->run(m3_dir);
  motors[3]->run(m4_dir);
}

void drive_forward()  { apply_directions(FORWARD,  FORWARD,  FORWARD,  FORWARD);  }
void drive_backward() { apply_directions(BACKWARD, BACKWARD, BACKWARD, BACKWARD); }
void turn_left()      { apply_directions(BACKWARD, BACKWARD, FORWARD,  FORWARD);  }
void turn_right()     { apply_directions(FORWARD,  FORWARD,  BACKWARD, BACKWARD); }
void stop_motors()    { apply_directions(RELEASE,   RELEASE,   RELEASE,   RELEASE);   }

void setup_motors() {
  set_motors(0, SPEED_NORMAL);
  stop_motors();
}