
// According to the board, cancel the corresponding macro definition
#define LILYGO_T5_V213
// #define LILYGO_T5_V22
// #define LILYGO_T5_V24
// #define LILYGO_T5_V28
// #define LILYGO_T5_V102

#include <boards.h>
#include <GxEPD.h>

#include <GxDEPG0213BN/GxDEPG0213BN.h>    // 2.13"  b/w  250*122  form DKE GROUP

#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
//#include <Fonts/FreeMonoBold9pt7b.h>
//#include <Fonts/FreeMonoBold12pt7b.h>
//#include <Fonts/FreeMonoBold18pt7b.h>
//#include <Fonts/FreeMonoBold24pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
//#include <Fonts/FreeSansBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

GxIO_Class io(SPI,  EPD_CS, EPD_DC,  EPD_RSET);
GxEPD_Class display(io, EPD_RSET, EPD_BUSY);

uint16_t box_w = 115;
uint16_t box_h = 40;

uint16_t cursor1_x = 6;
uint16_t cursor1_y = 30;

uint16_t cursor2_x = cursor1_x;
uint16_t cursor2_y = cursor1_y + box_h + 10;

uint16_t cursor3_x = cursor1_x + box_w + 16;
uint16_t cursor3_y = cursor1_y;

uint16_t cursorh_x = cursor3_x;
uint16_t cursorh_y = cursor3_y + box_h + 50;

static char outstr[15];
