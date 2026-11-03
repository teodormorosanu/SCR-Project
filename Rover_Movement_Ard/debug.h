#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>
#include "lights.h"
#include "motors.h"

// Produce o clipire (flash) controlata a farurilor
inline void flash_beams(uint8_t count = 3, uint16_t delay_ms = 150) {
  for (uint8_t i = 0; i < count; i++) {
    set_beams(true);
    delay(delay_ms);
    set_beams(false);
    delay(delay_ms);
  }
}

// Secventa completa de diagnosticare hardware (lumini + directii)
inline void run_hardware_diagnostics() {
  // 1. Test vizual: 3 flash-uri rapide pentru faruri
  flash_beams(3, 120);
  delay(500);

  // 2. Test motoare: impulsuri scurte pe fiecare directie
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

  // 3. Confirmare finala: 2 flash-uri lungi
  flash_beams(2, 300);
}

#endif // DEBUG_H