/**
 * @file mfs.hpp
 * @author ちみ/Chimi（https://github.com/Chimipupu）
 * @brief マルチファンクションシールド(MFS)のヘッダー
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MULTI_FUNCTION_SHIELD_HPP
#define MULTI_FUNCTION_SHIELD_HPP

#include <Arduino.h>
#include <stdint.h>
#include <string.h>

#define SEVEN_SEGMENT_LED_NUN     4   // 7セグLED数
#define MFS_BUZZER_PIN            3   // ブザー
#define MFS_BUTTON_S1_PIN        15   // ボタン1 (アクティブLOW)
#define MFS_BUTTON_S2_PIN        16   // ボタン2 (アクティブLOW)
#define MFS_BUTTON_S3_PIN        17   // ボタン3 (アクティブLOW)
#define MFS_LED_1_PIN            13   // LED1   (アクティブLOW)
#define MFS_LED_2_PIN            12   // LED2   (アクティブLOW)
#define MFS_LED_3_PIN            11   // LED3   (アクティブLOW)
#define MFS_LED_4_PIN            10   // LED4   (アクティブLOW)
#define MFS_74HC595_SDI_PIN      8    // 74HC595 シリアルデータ用ピン
#define MFS_74HC595_CLK_PIN      7    // 74HC595 クロック用ピン
#define MFS_74HC595_LATCH_PIN    4    // 74HC595 ラッチ用ピン

#endif /* MULTI_FUNCTION_SHIELD_HPP */