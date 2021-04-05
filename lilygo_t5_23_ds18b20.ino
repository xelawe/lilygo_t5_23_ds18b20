/*
    LilyGo Ink Screen Series Test
        - Created by Lewis he
*/

#include <WiFi.h>

#include <Ticker.h>

Ticker MinTick;
boolean min_tick = true;
boolean hour_tick = false;
int min_count = 0;


void tick_min() {
  min_count++;

  if (min_count >= 60) {
    hour_tick = true;
    min_count = 0;
  }

  min_tick = true;

}
