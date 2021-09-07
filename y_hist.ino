void update_hist() {

  int hist_ix = maxhist - 1;

  if (gv_temp2) {
    temp2CHist[hist_ix] = medianTemp2C.AddValue(tempC2);

    if (temp2CHist[hist_ix] > temp2CMax) {
      temp2CMax = temp2CHist[hist_ix];
      temp2CMaxIx = hist_ix;
    }
    if (temp2CHist[hist_ix] < temp2CMin) {
      temp2CMin = temp2CHist[hist_ix];
      temp2CMinIx = hist_ix;
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
        temp2CMaxIx = i;
      }
      if (temp2CHist[i] < temp2CMin) {
        temp2CMin = temp2CHist[i];
        temp2CMinIx = i;
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
