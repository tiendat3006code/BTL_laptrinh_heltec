#include "../include/oled_control.h"

oled_control::oled_control() {}

oled_control::~oled_control() {}

void oled_control::oled_init() {
   Heltec.begin(true, false, true);
   // Heltec.display->flipScreenVertically();
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

void oled_control::startDisplay() {
   Heltec.display->clear();
   Heltec.display->setFont(ArialMT_Plain_16);
   Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
   Heltec.display->drawString(0, 0, "Starting up");
   Heltec.display->setFont(ArialMT_Plain_16);
   Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
   Heltec.display->drawString(0, 16, "Speed: 250/255");
   Heltec.display->display();
}

void oled_control::test_display() {
   Heltec.display->setFont(ArialMT_Plain_10);

   // The coordinates define the left starting point of the text
   Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
   Heltec.display->drawString(0, 10, "Left aligned (0,10)");

   // The coordinates define the center of the text
   Heltec.display->setTextAlignment(TEXT_ALIGN_CENTER);
   Heltec.display->drawString(64, 22, "Center aligned (64,22)");

   // The coordinates define the right end of the text
   Heltec.display->setTextAlignment(TEXT_ALIGN_RIGHT);
   Heltec.display->drawString(128, 33, "Right aligned (128,33)");
}

void oled_control::display_state(int state) {
   Heltec.display->clear();
   Heltec.display->setFont(ArialMT_Plain_24);
   Heltec.display->setTextAlignment(TEXT_ALIGN_CENTER);
   Heltec.display->drawString(WIDTH / 2, HEIGHT / 2 - 20, "FORWARD");
   Heltec.display->display();
}