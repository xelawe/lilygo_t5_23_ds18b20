
void init_ds18b20( ) {

  // Start up the library
  sensors.begin();
}


void check_ds18b20() {
  sensors.requestTemperatures();
  
  tempC = sensors.getTempCByIndex(0);
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    //    Serial.print("Temperature for the device 1 (index 0) is: ");
    //    Serial.println(tempC);
    gv_temp1 = true;
  } else {
    //    Serial.println("Error: Could not read temperature data");
    gv_temp1 = false;
  }
  
  tempC2 = sensors.getTempCByIndex(1);
  if (tempC2 != DEVICE_DISCONNECTED_C)
  {
    //    Serial.print("Temperature for the device 1 (index 0) is: ");
    //    Serial.println(tempC);
    gv_temp2 = true;
  } else {
    //    Serial.println("Error: Could not read temperature data");
    gv_temp2 = false;
  }
}
