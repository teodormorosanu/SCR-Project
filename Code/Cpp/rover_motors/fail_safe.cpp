
#include <Arduino.h>
#include "FailSafe.h"

// --- SENSOR CONFIGURATION --- //

#define SENSOR_PIN A2
#define DANGER_THRESHOLD 400

// --- INTERNAL FUNCTIONS --- //

// Initialize the sensor pin
static void setup_sensor() {
    pinMode(SENSOR_PIN, INPUT);
}

// Read the raw analog sensor value
static int read_raw_data() {
    return analogRead(SENSOR_PIN);
}

// --- PUBLIC FUNCTION --- //

// Check if an obstacle is too close
bool danger_close() {

    // Read the sensor value
    int raw_data = read_raw_data();

    // Check the danger threshold
    if (raw_data >= DANGER_THRESHOLD) {
        return true;
    }

    return false;
}


//fail_safe.cpp
//fail_safe.h