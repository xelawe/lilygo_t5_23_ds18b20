void update_hist() {

  if (gv_temp2) {
    temp2CHist[maxhist - 1] = medianTemp2C.AddValue(tempC2);

    if (temp2CHist[maxhist - 1] > temp2CMax) {
      temp2CMax = temp2CHist[maxhist - 1];
    }
    if (temp2CHist[maxhist - 1] < temp2CMin) {
      temp2CMin = temp2CHist[maxhist - 1];
    }
  }

}


void shift_hist() {

  temp2CMin = 30;
  temp2CMax = -20;

  for (int i = 0; i < maxhist - 1; i++) {
    temp2CHist[i] = temp2CHist[i + 1];

    if ( temp2CHist[i] != 255) {
      if (temp2CHist[i] > temp2CMax) {
        temp2CMax = temp2CHist[i];
      }
      if (temp2CHist[i] < temp2CMin) {
        temp2CMin = temp2CHist[i];
      }
    }
  }

  update_hist();

}

void init_hist() {

  for (int i = 0; i < maxhist; i++) {
    temp2CHist[i] = 255;
  }
}
