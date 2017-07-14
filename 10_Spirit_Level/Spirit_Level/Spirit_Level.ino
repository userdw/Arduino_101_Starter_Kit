#include <U8g2lib.h>
#include <CurieIMU.h>
#define CALIBRATION_TIME 3000

//OLED pins CS, DC, RESET
//OLED coordinate start at top-left corner from 0
U8G2_SSD1306_128X64_VCOMH0_F_4W_HW_SPI oled(U8G2_R0, 10, 9, 8);

void drawLevelPage(int8_t level) {
  if (level < -90) {
    level = -90;
  }
  else if (level > 90) {
    level = 90;
  }

  oled.drawVLine(0, 16, 63);
  oled.drawVLine(63, 16, 63);
  for (byte i = 8; i < 32; i++) {
    if (i % 2) {
      oled.drawHLine(1, i * 2, 7);
      oled.drawHLine(63 - 7, i * 2, 7);
    }
    else {
      oled.drawHLine(1, i * 2, 10);
      oled.drawHLine(63 - 10, i * 2, 10);
    }
  }

  oled.setFont(u8g2_font_7x14B_mf);
  byte xPosString = (oled.getDisplayWidth() / 2) - (oled.getStrWidth("Inclination Level") / 2);
  oled.drawStr(xPosString, 12, "Inclination Level");

  oled.drawHLine(0, map(level, -90, 90, 63, 16), 63);
  xPosString = (oled.getDisplayWidth() * 3 / 4) - (oled.getStrWidth((String(level)).c_str()) / 2);
  oled.drawStr(xPosString, 48, String(level).c_str());

  xPosString = xPosString + oled.getStrWidth((String(level)).c_str());
  oled.setFont(u8g2_font_unifont_t_symbols);
  oled.drawUTF8(xPosString, 46, "°");
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
  oled.clearBuffer();
  drawLevelPage(map(aix, -16383, 16382, -90, 90));
  oled.sendBuffer();
}
