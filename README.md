# arduino_lib_soil_moisture

In order for the sensor to function correctly, it is necessary to carry out a calibration: the value obtained after immersing it in water corresponds to a humidity of 100%, whereas the value obtained in air is that relative to a humidity of 0%. These are indicative values for establishing a scale for evaluating the results.  

After calibration you can define this constants in the header file: 
```
#define DRY_VALUE <value obtained in air>
#define WET_VALUE <value obtained after immersing it in water>
```
