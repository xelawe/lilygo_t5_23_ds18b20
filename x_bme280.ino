#include <Wire.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; // use I2C interface

Adafruit_Sensor *bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor *bme_pressure = bme.getPressureSensor();
Adafruit_Sensor *bme_humidity = bme.getHumiditySensor();

float humid;
boolean gv_bme280 = false;
