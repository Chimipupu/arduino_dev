/**
 * @file common.hpp
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief 共通ヘッダー
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#ifndef COMMON_HPP
#define COMMON_HPP

#include <Arduino.h>
#include <stdint.h>
#include <string.h>
#include <avr/interrupt.h>

#define OB_LED_PIN    13

#define __DI           cli() // 割込みマスク（禁止）
#define __EI           sei() // 割込み許可

#endif /* COMMON_HPP */