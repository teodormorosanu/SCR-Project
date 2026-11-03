#include "debug.h"
#include "lights.h"
#include "motors.h"

void flash_beams(uint8_t count, uint16_t delay_ms) {
  for (uint8_t i = 0; i < count; i++) {
    set_beams(true);
    delay(delay_ms);
    set_beams(false);
    delay(delay_ms);
  }
}

void run_hardware_diagnostics() {
  // Test optic
  flash_beams(3, 120);
  delay(500);

  // Test directii motoare
  driveForward();
  delay(300);
  stopMotors();
  delay(200);

  driveBackward();
  delay(300);
  stopMotors();
  delay(200);

  turnLeft();
  delay(300);
  stopMotors();
  delay(200);

  turnRight();
  delay(300);
  stopMotors();
  delay(200);

  // Confirmare finala
  flash_beams(2, 300);
}