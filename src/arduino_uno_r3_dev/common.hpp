/**
 * @file common.hpp
 * @author ちみ/Chimi（https://github.com/Chimipupu）
 * @brief 共通ヘッダー
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef COMMON_HPP
#define COMMON_HPP

#include <Arduino.h>
#include <stdint.h>
#include <string.h>

#define SDI_74HC595_PIN          8    // 74HC595 Serial Data In PIN
#define CLK_74HC595_PIN          7    // 74HC595 Clock PIN
#define LATCH_74HC595_PIN        4    // 74HC595 Latch PIN
#define DYNAMIC_LIGHT_TIME_MS    5    // 7セグLED ダイナミック点灯時間(msec)

#endif /* COMMON_HPP */