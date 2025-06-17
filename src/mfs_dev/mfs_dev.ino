/**
 * @file arduino_uno_r3_dev.ino
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief Arduino IDE用inoファイル
 * @version 0.1
 * @date 2024-11-17
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include "common.hpp"
#include "app_main.hpp"

void setup()
{
    app_main_init();
}

void loop()
{
    app_main();
    delay(1000);
}