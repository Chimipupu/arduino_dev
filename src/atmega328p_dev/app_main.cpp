/**
 * @file app_main.cpp
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief アプリ メイン
 * @version 0.1
 * @date 2024-11-17
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include "app_main.hpp"

static uint8_t s_val = 0;

void app_main_init(void)
{
    // UART初期化
    Serial.begin(115200);

    // GPIO初期化
    pinMode(OB_LED_PIN, OUTPUT);
    digitalWrite(OB_LED_PIN, HIGH);

    // タイマー初期化
    drv_timer_init();
}

void app_main(void)
{
    uint32_t start_time = millis();

    digitalWrite(OB_LED_PIN, s_val);
    s_val = !s_val;

    uint32_t end_time = millis();
    Serial.print(F("処理時間 : "));
    Serial.print(end_time - start_time);
    Serial.print(F(" ms\n"));
}
