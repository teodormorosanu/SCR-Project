#ifndef LIGHTS_H
#define LIGHTS_H

#include <Arduino.h>

// Beam pin allocations
const uint8_t PIN_BEAM_LEFT  = A0;
const uint8_t PIN_BEAM_RIGHT = A1;

// Initialize beam pins as outputs and ensure they start turned off
inline void setup_beams() {
  pinMode(PIN_BEAM_LEFT, OUTPUT);
  pinMode(PIN_BEAM_RIGHT, OUTPUT);
  digitalWrite(PIN_BEAM_LEFT, LOW);
  digitalWrite(PIN_BEAM_RIGHT, LOW);
}

// Control left beam individually
inline void beam_left(bool mode) {
  digitalWrite(PIN_BEAM_LEFT, mode ? HIGH : LOW);
}

// Control right beam individually
inline void beam_right(bool mode) {
  digitalWrite(PIN_BEAM_RIGHT, mode ? HIGH : LOW);
}

// Control both beams simultaneously
inline void set_beams(bool mode) {
  digitalWrite(PIN_BEAM_LEFT, mode ? HIGH : LOW);
  digitalWrite(PIN_BEAM_RIGHT, mode ? HIGH : LOW);
}

#endif // LIGHTS_H
