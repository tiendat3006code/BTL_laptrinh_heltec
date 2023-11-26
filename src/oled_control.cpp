#include "../include/oled_control.h"

oled_control::oled_control()
    :
#ifdef PAGE_BUFFER
      u8g2(U8G2_R0,
           /* clock=*/15,
           /* data=*/4,
           /* reset=*/16)
#endif

#ifdef FULL_BUFFER
          u8g2(U8G2_R0,
               /* clock=*/15,
               /* data=*/4,
               /* reset=*/16)
#endif

#ifdef U8X8
              u8x8(/* clock=*/15,
                   /* data=*/4,
                   /* reset=*/16)
#endif
{
}

oled_control::~oled_control() {}

void oled_control::oled_init() {
   u8g2.begin();
}

void oled_control::oled_test() {
   u8g2.setFont(u8g2_font_logisoso32_tn);
   u8g2.drawStr(0, 63, "9");
}