#include <U8g2lib.h>
#define MEASUREMENT_INTERVAL 5000

//OLED pins CS, DC, RESET
//OLED coordinate start at top-left corner from 0
U8G2_SSD1306_128X64_VCOMH0_F_4W_HW_SPI oled(U8G2_R0, 10, 9, 8);
int16_t measurement[5] = { -1, -1, -1, -1, -1};
unsigned long oldTime = 30000;

void drawLevelPage(int16_t *temperature) {
  String temperatureStr = String(temperature[0]) + "°C";

  oled.drawVLine(0, 16, 63);
  oled.drawVLine(10, 16, 63);
  for (byte i = 8; i < 32; i++) {
    if (i % 2) {
      oled.drawHLine(1, i * 2, 1);
      oled.drawHLine(10 - 1, i * 2, 1);
    }
    else {
      oled.drawHLine(1, i * 2, 2);
      oled.drawHLine(10 - 2, i * 2, 2);
    }
  }

  oled.setFont(u8g2_font_7x14B_mf);
  byte xPosString = (oled.getDisplayWidth() / 2) - (oled.getStrWidth("Weather Station") / 2);
  oled.drawStr(xPosString, 12, "Weather Station");

  oled.drawHLine(0, map(temperature[0], 0, 100, 63, 16), 10);
  xPosString = oled.getDisplayWidth() * 19 / 64 - oled.getStrWidth(temperatureStr.c_str()) / 2;
  oled.drawStr(xPosString, 48, temperatureStr.c_str());

  oled.drawFrame(oled.getDisplayWidth() / 2, 16, oled.getDisplayWidth() / 2, 48);
  oled.setFont(u8g2_font_5x7_mf);

  for (byte i = 1; i < 5; i++) {
    if (temperature[i] == -1) temperatureStr = "NA";
    else temperatureStr = String(temperature[i]) + "°C";
    xPosString = oled.getDisplayWidth() * 3 / 4 - oled.getStrWidth(temperatureStr.c_str()) / 2;
    oled.drawStr(xPosString, 28 + ((i - 1) * 10), temperatureStr.c_str());
  }
}

void drawWelcomeMenu() {
  oled.setFont(u8g2_font_crox5t_tf);
  byte xPosString = (oled.getDisplayWidth() / 2) - (oled.getStrWidth("WELCOME") / 2);
  oled.drawStr(xPosString, 43, "WELCOME");
}

void setup(void) {
  oled.begin();
  oled.clearBuffer();
  drawWelcomeMenu();
  oled.sendBuffer();
  delay(2000);
}

void loop(void) {
  if (millis() - oldTime >= MEASUREMENT_INTERVAL) {
    float milliVoltage = analogRead(A0) * 3300.0 / 1023.0;
    float temperature = (milliVoltage - 500) / 10;

    if (temperature - (int)temperature > 0.5)
      temperature = (int)temperature + 1;
    else
      temperature = (int)temperature;

    for (byte i = 4; i > 0; i--)
      measurement[i] = measurement[i - 1];
    measurement[0] = (int)temperature;

    oled.clearBuffer();
    drawLevelPage(measurement);
    oled.sendBuffer();
    oldTime = millis();
  }
}
