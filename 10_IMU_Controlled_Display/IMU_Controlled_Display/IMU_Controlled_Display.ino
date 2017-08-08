#include <U8g2lib.h>
#include <CurieIMU.h>
#define CALIBRATION_TIME 3000

//OLED pins CS, DC, RESET
//OLED coordinate start at top-left corner from 0
U8G2_SSD1306_128X64_VCOMH0_F_4W_HW_SPI oled(U8G2_R0, 10, 9, 8);

//lcd characteristic
uint8_t horCenter = 0, verCenter = 0;

void drawDiscMenu(int x, int y, int z) {
  if (x < -16383) {
    x = -16383;
  } else if (x > 16382) {
    x = 16382;
  }
  if (y < -16383) {
    y = -16383;
  } else if (y > 16382) {
    y = 16382;
  }
  if (z < -16383) {
    z = -16383;
  } else if (z > 16382) {
    z = 16382;
  }

  x = map(x, -16383, 16382, 127, 0);
  y = map(y, -16383, 16382, 0, 63);
  z = map(z, -16383, 16382, 30, 3);

  oled.drawDisc(x, y, z);
}

void drawNoticeMenu(byte percentage) {
  if (percentage > 100) {
    percentage = 100;
  }

  oled.setFont(u8g2_font_timR10_tf);
  oled.drawStr(0, 12, "Keep the board laying");
  oled.drawStr(0, 26, "flat and motionless for");
  oled.drawStr(0, 40, "3 seconds");
  oled.drawFrame(oled.getDisplayWidth() / 8, 48, oled.getDisplayWidth() / 8 * 6, 5);
  oled.drawBox(oled.getDisplayWidth() / 8, 48, map(percentage, 0, 100, 0, oled.getDisplayWidth() / 8 * 6), 5);
}

void drawWelcomeMenu() {
  oled.setFont(u8g2_font_crox5t_tf);
  byte xPosString = (oled.getDisplayWidth() / 2) - (oled.getStrWidth("WELCOME") / 2);
  oled.drawStr(xPosString, 43, "WELCOME");
}

void setup(void) {
  oled.begin();
  CurieIMU.begin();
  CurieIMU.setAccelerometerRange(2);
  horCenter = oled.getDisplayWidth() / 2;
  verCenter = oled.getDisplayHeight() / 2;
  oled.clearBuffer();
  drawWelcomeMenu();
  oled.sendBuffer();
  delay(2000);
  unsigned long startCalibration = millis();
  while ((millis() - startCalibration) <= CALIBRATION_TIME) {
    CurieIMU.autoCalibrateAccelerometerOffset(X_AXIS, 0);
    CurieIMU.autoCalibrateAccelerometerOffset(Y_AXIS, 0);
    CurieIMU.autoCalibrateAccelerometerOffset(Z_AXIS, 1);
    oled.clearBuffer();
    drawNoticeMenu(map(millis() - startCalibration, 0, 3000, 0, 100));
    oled.sendBuffer();
  }
}

void loop(void) {
  int aix = CurieIMU.readAccelerometer(X_AXIS);
  int aiy = CurieIMU.readAccelerometer(Y_AXIS);
  int aiz = CurieIMU.readAccelerometer(Z_AXIS);

  oled.clearBuffer();
  drawDiscMenu(aix, aiy, aiz);
  oled.sendBuffer();
}
