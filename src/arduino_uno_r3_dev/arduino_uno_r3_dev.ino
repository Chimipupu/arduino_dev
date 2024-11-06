#include "common.hpp"
#include "drv_7segled.hpp"

void setup()
{
    pinMode(SDI_74HC595_PIN, OUTPUT);
    pinMode(CLK_74HC595_PIN, OUTPUT);
    pinMode(LATCH_74HC595_PIN, OUTPUT);
}

void loop()
{
    for(uint8_t i = 1; i <= 4; i++)
    {
        for(uint8_t k = 0; k <= 9; k++)
        {
            drv_7segu_led_ctrl(i, k);
            delay(100);
        }
    }
}