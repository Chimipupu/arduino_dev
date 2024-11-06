#include "common.hpp"
#include "drv_7segled.hpp"

uint8_t s_7segled_dat_buf[SEVEN_SEGMENT_LED_NUN] = { 0x03, 0x02, 0x01, 0x00 };

void setup()
{
    pinMode(SDI_74HC595_PIN, OUTPUT);
    pinMode(CLK_74HC595_PIN, OUTPUT);
    pinMode(LATCH_74HC595_PIN, OUTPUT);
}

void loop()
{
    drv_7segu_led_dynamic(&s_7segled_dat_buf[0]);
}