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
#include <stdint.h>
#include <EEPROM.h>

bool g_main_proc_flg = false;
static uint8_t s_led_val = 0;

static void mcu_info_print(void);
static void eeprom_dump_print(uint32_t dump_size);

static void eeprom_dump_print(uint32_t dump_size)
{
    uint8_t i, val;
    uint8_t new_line_size = 16;
    uint32_t addr;

    Serial.println(F("[EEPROM Dump]"));
    for (addr = 0; addr < dump_size; addr++)
    {
        if (addr % new_line_size == 0) {
            if (addr != 0) Serial.println();
                Serial.print(F("0x"));
                for (i = String(addr, HEX).length(); i < 4; i++)
                {
                    Serial.print(F("0"));
                }
                Serial.print(addr, HEX);
                Serial.print(F(": "));
        }
        val = EEPROM.read(addr);
        if (val < 0x10) {
            Serial.print(F("0"));
        } else {
            Serial.print(val, HEX);
        }
            Serial.print(F(" "));
    }
    Serial.println();
}

static void mcu_info_print(void)
{
    Serial.print(F("[ATmega328P F/W Test]\n"));
    Serial.print(F("EEPROM Size : "));
    Serial.print(OC_EEPROM_SIZE);
    Serial.print(F(" Byte\n"));
#ifdef _DEBUG_USE_
    eeprom_dump_print(OC_EEPROM_SIZE);
#endif /* _DEBUG_USE_ */
}

/**
 * @brief アプリ初期化
 * 
 */
void app_main_init(void)
{
    // UART初期化
    Serial.begin(115200);
    mcu_info_print();

    // GPIO初期化
    pinMode(OB_LED_PIN, OUTPUT);
    digitalWrite(OB_LED_PIN, HIGH);

    // タイマー初期化
    drv_timer_init();
}

/**
 * @brief アプリメイン
 * 
 */
void app_main(void)
{
    volatile uint32_t start_time, end_time, proc_time;

    if(g_main_proc_flg != false)
    {
        // Serial.println(F("[App Main]"));

#ifdef _DEBUG_USE_
        start_time = micros();
#endif /* _DEBUG_USE_ */

        digitalWrite(OB_LED_PIN, s_led_val);
        s_led_val = !s_led_val;

#ifdef _DEBUG_USE_
        end_time = micros();
        proc_time = end_time - start_time;
        Serial.print(F("Proc Time : "));
        Serial.print(proc_time);
        Serial.print(F("[us]\n"));
#endif /* _DEBUG_USE_ */

        g_main_proc_flg = false;
    }
}