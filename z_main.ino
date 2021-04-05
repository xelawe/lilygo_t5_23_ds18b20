
void setup(void)
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  init_hist();

  init_ds18b20( );

  init_bme280();

  init_epd( );

  MinTick.attach(60, tick_min);

  Serial.println("setup done");
}


void loop()
{

  if (min_tick) {

    check_ds18b20();

    check_bme280();

    disp_vals();

    update_hist();


    if (hour_tick) {
      shift_hist();

      hour_tick = false;
    }

    draw_hist();
    min_tick = false;
  }


  delay(500);
}
