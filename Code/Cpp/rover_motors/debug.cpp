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
  drive_forward();
  delay(300);
  stop_motors();
  delay(200);

  drive_backward();
  delay(300);
  stop_motors();
  delay(200);

  turn_left();
  delay(300);
  stop_motors();
  delay(200);

  turn_right();
  delay(300);
  stop_motors();
  delay(200);

  // Confirmare finala
  flash_beams(2, 300);
}