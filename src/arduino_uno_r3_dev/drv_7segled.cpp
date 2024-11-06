/**
 * @file drv_7segled.cpp
 * @author ちみ/Chimi（https://github.com/Chimipupu）
 * @brief 7セグLEDドライバ
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "common.hpp"
#include "drv_7segled.hpp"

void drv_7segu_led_ctrl(uint8_t colum, uint8_t data)
{
    uint8_t col = SEVEN_SEGMENT_LED_COLUMN_1;
    uint8_t dat = SEVEN_SEGMENT_LED_NONE;

    switch (colum)
    {
        case 2:
            col = SEVEN_SEGMENT_LED_COLUMN_2;
            break;

        case 3:
            col = SEVEN_SEGMENT_LED_COLUMN_3;
            break;

        case 4:
            col = SEVEN_SEGMENT_LED_COLUMN_4;
            break;

        default:
            col = SEVEN_SEGMENT_LED_COLUMN_1;
            break;
    }

    switch (data)
    {
        case 0x00:
            dat = SEVEN_SEGMENT_LED_0;
            break;
        case 0x01:
            dat = SEVEN_SEGMENT_LED_1;
            break;
        case 0x02:
            dat = SEVEN_SEGMENT_LED_2;
            break;
        case 0x03:
            dat = SEVEN_SEGMENT_LED_3;
            break;
        case 0x04:
            dat = SEVEN_SEGMENT_LED_4;
            break;
        case 0x05:
            dat = SEVEN_SEGMENT_LED_5;
            break;
        case 0x06:
            dat = SEVEN_SEGMENT_LED_6;
            break;
        case 0x07:
            dat = SEVEN_SEGMENT_LED_7;
            break;
        case 0x08:
            dat = SEVEN_SEGMENT_LED_8;
            break;
        case 0x09:
            dat = SEVEN_SEGMENT_LED_9;
            break;
        case 0x0A:
            dat = SEVEN_SEGMENT_LED_A;
            break;
        case 0x0B:
            dat = SEVEN_SEGMENT_LED_B;
            break;
        case 0x0C:
            dat = SEVEN_SEGMENT_LED_C;
            break;
        case 0x0D:
            dat = SEVEN_SEGMENT_LED_D;
            break;
        case 0x0E:
            dat = SEVEN_SEGMENT_LED_E;
            break;
        case 0x0F:
            dat = SEVEN_SEGMENT_LED_F;
            break;
        default:
            dat = SEVEN_SEGMENT_LED_NONE;
            break;
    }

    digitalWrite(LATCH_74HC595_PIN, LOW);
    shiftOut(SDI_74HC595_PIN, CLK_74HC595_PIN, LSBFIRST, dat);
    shiftOut(SDI_74HC595_PIN, CLK_74HC595_PIN, LSBFIRST, col);
    digitalWrite(LATCH_74HC595_PIN, HIGH);
    delay(DYNAMIC_LIGHT_TIME_MS);
}