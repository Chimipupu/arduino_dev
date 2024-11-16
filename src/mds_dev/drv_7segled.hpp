/**
 * @file drv_7segled.hpp
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief 7セグLEDドライバ ヘッダー
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef DRV_7SEGLED_HPP
#define DRV_7SEGLED_HPP

#include <stdint.h>
#include <string.h>

// 7セグ「a b c d e f g h」(MSBがa、ビットが0で点灯、1が消灯)
#define SEVEN_SEGMENT_LED_0            0b00000011   // 7セグの「0」表示
#define SEVEN_SEGMENT_LED_1            0b10011111   // 7セグの「1」表示
#define SEVEN_SEGMENT_LED_2            0b00100101   // 7セグの「2」表示
#define SEVEN_SEGMENT_LED_3            0b00001101   // 7セグの「3」表示
#define SEVEN_SEGMENT_LED_4            0b10011001   // 7セグの「4」表示
#define SEVEN_SEGMENT_LED_5            0b01001001   // 7セグの「5」表示
#define SEVEN_SEGMENT_LED_6            0b01000001   // 7セグの「6」表示
#define SEVEN_SEGMENT_LED_7            0b00011111   // 7セグの「7」表示
#define SEVEN_SEGMENT_LED_8            0b00000001   // 7セグの「8」表示
#define SEVEN_SEGMENT_LED_9            0b00001001   // 7セグの「9」表示
#define SEVEN_SEGMENT_LED_A            0b00010001   // 7セグの「A」表示
#define SEVEN_SEGMENT_LED_B            0b11000001   // 7セグの「B」表示
#define SEVEN_SEGMENT_LED_C            0b01100011   // 7セグの「C」表示
#define SEVEN_SEGMENT_LED_D            0b10000101   // 7セグの「D」表示
#define SEVEN_SEGMENT_LED_E            0b01100001   // 7セグの「E」表示
#define SEVEN_SEGMENT_LED_F            0b01110001   // 7セグの「F」表示
#define SEVEN_SEGMENT_LED_DOT          0b00000001   // 7セグの「.(ドット)」表示
#define SEVEN_SEGMENT_LED_NONE         0b11111111   // 7セグの全消灯
#define SEVEN_SEGMENT_LED_ALL          0b00000000   // 7セグの全点灯

#define SEVEN_SEGMENT_LED_COLUMN_1     0b00010000   // 7セグ1桁目
#define SEVEN_SEGMENT_LED_COLUMN_2     0b00100000   // 7セグ2桁目
#define SEVEN_SEGMENT_LED_COLUMN_3     0b01000000   // 7セグ3桁目
#define SEVEN_SEGMENT_LED_COLUMN_4     0b10000000   // 7セグ4桁目

#define DYNAMIC_LIGHT_TIME_MS          6            // 7セグLED ダイナミック点灯時間(msec)

void drv_num_to_7seg(uint32_t num, uint8_t *p_buf);

#endif /* DRV_7SEGLED_HPP */