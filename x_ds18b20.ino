// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include "MedianFilterLib.h"

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 32

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

float tempC;
float tempC2;

boolean gv_temp1 = false;
boolean gv_temp2 = false;

#define maxhist 24
float temp2CHist[maxhist];
float temp2CMin = 30;
float temp2CMax = -20;
int temp2CMinIx = maxhist -1;
int temp2CMaxIx = maxhist -1;

MedianFilter<float> medianTemp2C(60);
