/** 
 * Library to manage soil moisture sensor
 * Tested with captor YL69 and module HC-38
*/
#ifndef _SOIL_SENSOR_H_
#define _SOIL_SENSOR_H_


class MoistureSensor {
    public:
        MoistureSensor(int sensor_pin, int dry_value, int wet_value);
        int get_soil_moisture_percent();
        int read_sensor();
        void calibrate();

    private:
        int _sensor_pin, _dry_value, _wet_value;
};

#endif
