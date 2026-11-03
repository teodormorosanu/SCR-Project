#include "lights.h"
#include "motors.h"

// Comenteaza linia de mai jos daca nu vrei autotestul cu flash-uri la pornire
#define DEBUG_MODE
// sau cu pragma once
#ifdef DEBUG_MODE
  #include "debug.h"
#endif

// Proceseaza fiecare comanda primita pe seriala de la Raspberry Pi
void handle_command(char cmd) {
  switch (cmd) {
    // Comenzi de miscare
    case 'F': drive_forward();  break;
    case 'B': drive_backward(); break;
    case 'L': turn_left();      break;
    case 'R': turn_right();     break;

    // Oprire de urgenta
    case 'E':
      stop_motors();
      break;

    // Trepte PWM de viteza
    case '1': set_motors(0, SPEED_SLOW);   break;
    case '2': set_motors(0, SPEED_NORMAL); break;
    case '3': set_motors(0, SPEED_FAST);   break;

    // Control faruri
    case 'H': set_beams(true);  break;
    case 'h': set_beams(false); break;

    #ifdef DEBUG_MODE
    case 'X': flash_beams(3, 150); break;
    case 'P': set_beams(true); break;
    case 'p': set_beams(false); break;
    #endif

    default:
      break;
  }
}

void setup() {
  Serial.begin(9600);[cite: 1]
  setup_motors();
  setup_beams();

  #ifdef DEBUG_MODE
    run_hardware_diagnostics();
  #endif
}

void loop() {
  if (Serial.available() > 0) {[cite: 1]
    char incoming_char = Serial.read();[cite: 1]
    handle_command(incoming_char);
  }
}