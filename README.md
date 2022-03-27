# arduino_lib_soil_moisture

Library to interfere with a soil moisture sensor

## Calibration 

In order for the sensor to function correctly, it is necessary to carry out a calibration: the value obtained after immersing it in water corresponds to a humidity of 100%, whereas the value obtained in air is that relative to a humidity of 0%. These are indicative values for establishing a scale for evaluating the results.  

```
#define MOISTURE_SENSOR_PIN "sensor_pin";
MoistureSensor moisture_sensor(MOISTURE_SENSOR_PIN);
moisture_sensor.calibrate();
```

After calibration you can define this constants: 
```
#define DRY_VALUE <value obtained in air>
#define WET_VALUE <value obtained after immersing it in water>
```

## Usage
 
```
#define MOISTURE_SENSOR_PIN 36 
#define DRY_VALUE "value obtained in air" 
#define WET_VALUE "value obtained after immersing it in water" 

MoistureSensor moisture_sensor(MOISTURE_SENSOR_PIN, DRY_VALUE, WET_VALUE);

moisture_sensor.get_soil_moisture_percent()
moisture_sensor.read_sensor()
```
