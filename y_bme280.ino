void init_bme280() {

  if (!bme.begin(0x76)) {
    Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
    gv_bme280 = false;
  } else {
    gv_bme280 = true;

    bme_temp->printSensorDetails();
    bme_pressure->printSensorDetails();
    bme_humidity->printSensorDetails();
  }
}

void check_bme280() {

  if ( gv_bme280 == false ) {
    return;
  }

  sensors_event_t temp_event, pressure_event, humidity_event;
  bme_temp->getEvent(&temp_event);
  bme_pressure->getEvent(&pressure_event);
  bme_humidity->getEvent(&humidity_event);

  //  Serial.print(F("Temperature = "));
  //  Serial.print(temp_event.temperature);
  //  Serial.println(" *C");

  humid = humidity_event.relative_humidity;
  //  Serial.print(F("Humidity = "));
  //  Serial.print(humidity_event.relative_humidity);
  //  Serial.println(" %");
  //
  //  Serial.print(F("Pressure = "));
  //  Serial.print(pressure_event.pressure);
  //  Serial.println(" hPa");
  //
  //  Serial.println();
}
