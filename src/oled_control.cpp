#include "../include/oled_control.h"

oled_control::oled_control() {}

oled_control::~oled_control() {}

void oled_control::oled_init() {
   Heltec.begin(true, false, true);
   Heltec.display->flipScreenVertically();
   Heltec.display->setBrightness(255);
   Heltec.display->setFont(ArialMT_Plain_10);
   fill_rect();
}

void oled_control::fill_rect() {
   uint8_t color = 1;
   for (int16_t i = 0; i < HEIGHT / 2; i += 3) {
      Heltec.display->setColor((color % 2 == 0) ? BLACK
                                                : WHITE);  // alternate colors
      Heltec.display->fillRect(i, i, WIDTH - i * 2, HEIGHT - i * 2);
      Heltec.display->display();
      delay(10);
      color++;
   }
   Heltec.display->setColor(WHITE);
   Heltec.display->clear();
}