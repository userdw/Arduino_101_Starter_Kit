#include <U8g2lib.h>
#include <CurieIMU.h>
#define CALIBRATION_TIME 3000

//variable for OLED
U8G2_SSD1306_128X64_VCOMH0_F_4W_HW_SPI u8g2(U8G2_R0, /*cs=*/ 10, /*dc=*/ 9, /*reset=*/ 8);

void drawLevelPage(int8_t level) {
  if (level < -90) {
    level = -90;
  }
  else if (level > 90) {
    level = 90;
  }

  u8g2.setFont(u8g2_font_crox3cb_mn);
  u8g2.drawVLine(0, 16, 63);
  u8g2.drawVLine(63, 16, 63);
  for (byte i = 8; i < 32; i++) {
    if (i % 2) {
      u8g2.drawHLine(1, i * 2, 7);
      u8g2.drawHLine(63 - 7, i * 2, 7);
    }
    else {
      u8g2.drawHLine(1, i * 2, 10);
      u8g2.drawHLine(63 - 10, i * 2, 10);
    }
  }

  u8g2.setFont(u8g2_font_7x14B_mf);
  byte xPosString = (u8g2.getDisplayWidth() / 2) - (u8g2.getStrWidth("Inclination Level") / 2);
  u8g2.drawStr(xPosString, 12, "Inclination Level");

  u8g2.drawHLine(0, map(level, -90, 90, 63, 16), 63);
  xPosString = (u8g2.getDisplayWidth() * 3 / 4) - (u8g2.getStrWidth((String(level)).c_str()) / 2);
  u8g2.drawStr(xPosString, 48, String(level).c_str());

  xPosString = xPosString + u8g2.getStrWidth((String(level)).c_str());
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawUTF8(xPosString, 46, "°");
}

void drawNoticeMenu(byte percentage) {
  if (percentage > 100) {
    percentage = 100;
  }

  u8g2.setFont(u8g2_font_timR10_tf);
  u8g2.drawStr(0, 12, "Keep the board laying");
  u8g2.drawStr(0, 26, "flat and motionless for");
  u8g2.drawStr(0, 40, "3 seconds");
  u8g2.drawFrame(u8g2.getDisplayWidth() / 8, 48, u8g2.getDisplayWidth() / 8 * 6, 5);
  u8g2.drawBox(u8g2.getDisplayWidth() / 8, 48, map(percentage, 0, 100, 0, u8g2.getDisplayWidth() / 8 * 6), 5);
}

void drawWelcomeMenu() {
  u8g2.setFont(u8g2_font_crox5t_tf);
  byte xPosString = (u8g2.getDisplayWidth() / 2) - (u8g2.getStrWidth("WELCOME") / 2);
  u8g2.drawStr(xPosString, 43, "WELCOME");
}

void setup(void) {
  u8g2.begin();
  CurieIMU.begin();
  CurieIMU.setAccelerometerRange(2);
  u8g2.clearBuffer();
  drawWelcomeMenu();
  u8g2.sendBuffer();
  delay(2000);
  unsigned long startCalibration = millis();
  while ((millis() - startCalibration) <= CALIBRATION_TIME) {
    CurieIMU.autoCalibrateAccelerometerOffset(X_AXIS, 0);
    CurieIMU.autoCalibrateAccelerometerOffset(Y_AXIS, 0);
    CurieIMU.autoCalibrateAccelerometerOffset(Z_AXIS, 1);
    u8g2.clearBuffer();
    drawNoticeMenu(map(millis() - startCalibration, 0, 3000, 0, 100));
    u8g2.sendBuffer();
  }
}

void loop(void) {
  int aix = CurieIMU.readAccelerometer(X_AXIS);
  u8g2.clearBuffer();
  drawLevelPage(map(aix, -16383, 16382, -90, 90));
  u8g2.sendBuffer();
}
