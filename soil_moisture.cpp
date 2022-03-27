#include "soil_moisture.h"

#include <Arduino.h>

#define N_MEASURE 3     // Number of measures performed by the sensor to make an average 
 
#define MIN 0
#define MAX 100
#define DEFAULT_DRY_VALUE 2500
#define DEFAULT_WET_VALUE 500

/**
 * Constructor
*/
MoistureSensor::MoistureSensor(int sensor_pin, int dry_value=DEFAULT_DRY_VALUE, int wet_value=DEFAULT_WET_VALUE) {
    this->_sensor_pin = sensor_pin;
    this->_dry_value = dry_value;
    this->_wet_value = wet_value;
}
/**
* Get the percentage of soil moisture
*
* @return soil moisture percentage
*/
int MoistureSensor::get_soil_moisture_percent() {
  int raw_data = 0;

  for (int i = 0; i < N_MEASURE; i++){  // Reads the sensor "N" times, by default N_MEASURE=3
    raw_data += read_sensor();
  }

  raw_data = raw_data / N_MEASURE;  // Averages the data obtained by the sensor 
  int soil_moisture_percent = map(raw_data, _dry_value, _wet_value, MIN, MAX);  // Calculates the percentage of humidity

  return soil_moisture_percent;
}

int MoistureSensor::read_sensor() {
  digitalWrite(_sensor_pin, HIGH);  // Sets the sensor to on 
  delay(500);
 
  int value = analogRead(_sensor_pin);

  digitalWrite(_sensor_pin, LOW); // Sets the sensor to off
  delay(500);

  return value;
}


void MoistureSensor::calibrate() {
  Serial.println("Reading From the Sensor ...");
  int value = read_sensor();
  Serial.printf("Raw sensor value: %i\n", value);
  delay(500);
}