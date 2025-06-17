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
static uint8_t s_led_val = 0;

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
                for (int i = String(address, HEX).length(); i < 4; i++)
                {
                    Serial.print("0");
                }
                Serial.print(address, HEX);
                Serial.print(": ");
        }
        byte value = EEPROM.read(address);
        if (value < 0x10) {
            Serial.print("0");
        } else {
            Serial.print(value, HEX);
        }
        Serial.print(" ");
    }
    Serial.println();
}

static void mcu_info_print(void)
{
    uint32_t eeprom_size = 0;

    Serial.print("[ATmega328P F/W Test]\n");
    eeprom_size = EEPROM.length();
    Serial.print("EEPROM Size : ");
    Serial.print(eeprom_size);
    Serial.print(" Byte\n");
    eeprom_dump();
}
#endif /* _DEBUG_USE_ */

/**
 * @brief アプリ初期化
 * 
 */
void app_main_init(void)
{
    // UART初期化
    Serial.begin(115200);
#ifdef _DEBUG_USE_
    mcu_info_print();
#endif /* _DEBUG_USE_ */

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

    while (g_main_proc_flg)
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
    }
}