#include "lights.h"

void setup_beams() {
  pin_mode(PIN_BEAM_LEFT, OUTPUT);
  pin_mode(PIN_BEAM_RIGHT, OUTPUT);
  digital_write(PIN_BEAM_LEFT, LOW);
  digital_write(PIN_BEAM_RIGHT, LOW);
}

void beam_left(bool mode) {
  digital_write(PIN_BEAM_LEFT, mode ? HIGH : LOW);
}

void beam_right(bool mode) {
  digital_write(PIN_BEAM_RIGHT, mode ? HIGH : LOW);
}

void set_beams(bool mode) {
  digital_write(PIN_BEAM_LEFT, mode ? HIGH : LOW);
  digital_write(PIN_BEAM_RIGHT, mode ? HIGH : LOW);
}