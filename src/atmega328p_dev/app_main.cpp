#include <stdint.h>
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

#ifdef _DEBUG_USE_
#include <EEPROM.h>
static void eeprom_dump(void);
static void mcu_info_print(void);
#endif /* _DEBUG_USE_ */

bool g_main_proc_flg = false;
static uint8_t s_val = 0;

#ifdef _PWM_USE_
static void led_fade(uint8_t pin);
static bool s_led_fade_amount = false;
static uint8_t s_led_pwm_val = 0;

static void led_fade(uint8_t pin)
{
    analogWrite(pin, s_led_pwm_val);

    if (s_led_fade_amount != true) {
        s_led_pwm_val++;
        if (s_led_pwm_val == 255){
            s_led_fade_amount = !s_led_fade_amount;
        }
    } else {
        s_led_pwm_val--;
        if (s_led_pwm_val == 0){
            s_led_fade_amount = !s_led_fade_amount;
        }
    }
}
#endif /* _PWM_USE_ */


#ifdef _DEBUG_USE_
#include <EEPROM.h>
static void eeprom_dump(void)
{
    const int EEPROM_SIZE = EEPROM.length();
    const int ROW_SIZE = 16;

    Serial.println("[EEPROM Dump]");
    for (int address = 0; address < EEPROM_SIZE; address++) {
        if (address % ROW_SIZE == 0) {
            if (address != 0) Serial.println();
                Serial.print("0x");
                Serial.print(address, HEX);
                for (int i = String(address, HEX).length(); i < 4; i++)
                {
                    Serial.print("0");
                }
                Serial.print(": ");
        }
        byte value = EEPROM.read(address);
        if (value < 0x10) Serial.print("0");
        Serial.print(value, HEX);
        Serial.print(" ");
    }
    Serial.println();
}

static void mcu_info_print(void)
{
    uint32_t eeprom_size = 0;

    Serial.begin(115200);
    Serial.print("[ATmega328P F/W Test]\n");
    eeprom_size = EEPROM.length();
    Serial.print("EEPROM Size : ");
    Serial.print(eeprom_size);
    Serial.print(" Byte\n");
    eeprom_dump();
}
#endif /* _DEBUG_USE_ */

void app_main_init(void)
{
    // UART初期化
#ifdef _DEBUG_USE_
    mcu_info_print();
#endif /* _DEBUG_USE_ */

    // GPIO初期化
#ifdef _PWM_USE_
    // NOP
#else
    pinMode(OB_LED_PIN, OUTPUT);
    digitalWrite(OB_LED_PIN, HIGH);
#endif /* _PWM_USE_ */

    // タイマー初期化
    drv_timer_init();
}

void app_main(void)
{
    while (g_main_proc_flg)
    {
#ifdef _DEBUG_USE_
        // uint32_t start_time = millis();
#endif /* _DEBUG_USE_ */

#ifdef _PWM_USE_
        // led_fade(OB_LED_PIN);
#else
        digitalWrite(OB_LED_PIN, s_val);
        s_val = !s_val;
#endif /* _PWM_USE_ */

#ifdef _DEBUG_USE_
        // uint32_t end_time = millis();
        // Serial.print(F("処理時間 : "));
        // Serial.print(end_time - start_time);
        // Serial.print(F(" ms\n"));
#endif /* _DEBUG_USE_ */

        g_main_proc_flg = false;
    }
}
