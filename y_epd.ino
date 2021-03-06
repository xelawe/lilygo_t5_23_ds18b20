void init_epd() {
  SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);

  display.init(); // enable diagnostic output on Serial

  display.setRotation(0);
  display.update();

  // partial update to full screen to preset for partial update of box window
  // (this avoids strange background effects)
  display.updateWindow(0, 0, GxEPD_WIDTH - 6, GxEPD_HEIGHT, false);
}

void disp_vals() {
  display.setRotation(0);
  display.fillRect(0, 0, GxEPD_WIDTH - 6, GxEPD_HEIGHT, GxEPD_WHITE);

  int line_top = 43;//GxEPD_WIDTH - 44;
  display.drawFastVLine(line_top, 0, GxEPD_HEIGHT, GxEPD_BLACK);
  line_top--;
  display.drawFastVLine(line_top, 0, GxEPD_HEIGHT, GxEPD_BLACK);

  display.setRotation(3);

  //display.updateWindow(0, 0, GxEPD_WIDTH - 6, GxEPD_HEIGHT, true);


  disp_value( tempC, cursor1_x, cursor1_y, "c", gv_temp1);
  disp_value( humid, cursor3_x, cursor3_y, "%", gv_bme280);

  disp_value( tempC2, cursor2_x, cursor2_y, "c", gv_temp2);
  disp_value_s( temp2CMin, cursor2_x, cursor2_y + 35, "c", gv_temp2);
  disp_value_s( temp2CMax, cursor2_x + (box_w / 2), cursor2_y + 35 , "c", gv_temp2);

  draw_hist();

  //display.updateWindow(0, 0, GxEPD_HEIGHT, GxEPD_WIDTH - 6, true);

  display.update();
}

void disp_value_s(float iv_val, int iv_x, int iv_y, char *iv_unit, boolean iv_valid) {

  //uint16_t box_x = iv_x - 2;
  //uint16_t box_y = iv_y - ( box_h - 15) + 7;

  //display.fillRect(box_x, box_y, box_w / 2, box_h - 15, GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&FreeSansBold9pt7b);
  display.setCursor(iv_x, iv_y);

  if (iv_valid) {
    dtostrf(iv_val, 3, 1, outstr);
    display.print(outstr);
  } else {
    display.print("-XX.X");
  }
  //display.setFont(&FreeSansBold12pt7b);
  //display.print(iv_unit);

  //display.drawRect(box_x, box_y, box_w / 2, box_h - 15, GxEPD_BLACK);
  //display.updateWindow(box_x - 1, box_y - 1, box_w / 2 + 2, box_h - 15 + 3, true);
}

void disp_value(float iv_val, int iv_x, int iv_y, char *iv_unit, boolean iv_valid) {

  //uint16_t box_x = iv_x - 2;
  //uint16_t box_y = iv_y - box_h + 7;

  //display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&FreeSansBold18pt7b);
  display.setCursor(iv_x, iv_y);

  if (iv_valid) {
    dtostrf(iv_val, 3, 1, outstr);
    display.print(outstr);
  } else {
    display.print("-XX.X");
  }
  display.setFont(&FreeSansBold12pt7b);
  display.print(iv_unit);

  //display.drawRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
  //display.updateWindow(box_x - 1, box_y - 1, box_w + 2, box_h + 3, true);
}

void draw_hist() {
  int hist_height = (box_h * 2);
  int hist_width = 24 * 5;

  int hist_x = disp_width - hist_width;
  int hist_y = disp_height;

  int hist_step = 5;

  // Draw Zero dashed Line
  int x = hist_x;
  int y = hist_y - map(0, -20, 30, 0, hist_height);
  for (int i = 0; i < maxhist; i++) {
    if (i % 4 == 0) {
      display.drawLine(x, y - 2, x, y + 2, GxEPD_BLACK);
    }

    display.drawLine(x, y, x + 3, y, GxEPD_BLACK);
    display.drawLine(x + 3, y, x + hist_step, y, GxEPD_WHITE);

    x = x + hist_step;
  }

  // Draw Values
  x = hist_x;
  float lv_val1 = temp2CHist[0];
  if ( lv_val1 == 255) {
    lv_val1 = 0;
  }
  y = hist_y - map(lv_val1, -20, 30, 0, hist_height);

  for (int i = 1; i < maxhist; i++) {
    float lv_val = temp2CHist[i];
    if ( lv_val == 255) {
      lv_val = 0;
    }

    int x1 = x + 5;
    int y1 = hist_y - map(lv_val, -20, 30, 0, hist_height);
    display.drawLine(x, y, x1, y1, GxEPD_BLACK);

    if (i == temp2CMinIx || i == temp2CMaxIx) {
      display.drawCircle(x1, y1, 2, GxEPD_BLACK);
    }

    x = x1;
    y = y1;
  }

  //display.drawRect(hist_x, hist_y - hist_height, hist_width, hist_height,  GxEPD_BLACK);
  display.drawFastVLine(hist_x, hist_y - hist_height, hist_height, GxEPD_BLACK);
}

//void draw_house(int iv_x, int iv_y) {
//  int lv_width = 120;
//  int lv_height = 92;
//  int lv_roof_dist = 2;
//  display.drawRect(iv_x, iv_y, lv_width, lv_height, GxEPD_BLACK);
//  display.drawRect(iv_x + 1, iv_y + 1, lv_width - 2, lv_height - 2, GxEPD_BLACK);
//
//  display.drawTriangle(iv_x - lv_roof_dist, iv_y, iv_x + (lv_width / 2), iv_y - 30, iv_x + lv_width + lv_roof_dist, iv_y, GxEPD_BLACK);
//  display.drawTriangle(iv_x - lv_roof_dist + 2, iv_y, iv_x + (lv_width / 2), iv_y - 30 + 1, iv_x + lv_width + lv_roof_dist - 2, iv_y, GxEPD_BLACK);
//  display.update();
//}
