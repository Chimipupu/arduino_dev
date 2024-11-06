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
#include "mfs.hpp"
#include "drv_7segled.hpp"

static void dynamic_7segu_led(uint8_t *p_dat_buf);
static void seven_segment_led_ctrl(uint8_t colum, uint8_t data);

static void seven_segment_led_ctrl(uint8_t colum, uint8_t data)
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
        case 0xFF:
        default:
            dat = SEVEN_SEGMENT_LED_NONE;
            break;
    }

    digitalWrite(MFS_74HC595_LATCH_PIN, LOW);
    shiftOut(MFS_74HC595_SDI_PIN, MFS_74HC595_CLK_PIN, LSBFIRST, dat);
    shiftOut(MFS_74HC595_SDI_PIN, MFS_74HC595_CLK_PIN, LSBFIRST, col);
    digitalWrite(MFS_74HC595_LATCH_PIN, HIGH);
}

static void dynamic_7segu_led(uint8_t *p_dat_buf)
{
    for(uint8_t i = 1; i <= 4; i++)
    {
        seven_segment_led_ctrl(i, *p_dat_buf);
        delay(DYNAMIC_LIGHT_TIME_MS);
        p_dat_buf++;
    }
}

void drv_num_to_7seg(uint32_t num, uint8_t *p_buf)
{
    p_buf[3] = num / 1000;          // 7セグ桁1目 = 数値の1000の位
    p_buf[2] = (num / 100) % 10;    // 7セグ桁2目 = 数値の100の位
    p_buf[1] = (num / 10) % 10;     // 7セグ桁3目 = 数値の10の位
    p_buf[0] = num % 10;            // 7セグ桁4目 = 数値の1の位
    dynamic_7segu_led(p_buf);
}