/**
 * @file ds3231_dev.ino
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief DS3231 RTCのArduino Uno実験ファイル
 * @version 0.1
 * @date 2024-11-29
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include "Arduino.h"
#include "uRTCLib.h"

uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup()
{
    Serial.begin(115200);
    delay(3000);
    URTCLIB_WIRE.begin();
    rtc.set(0, 0, 12, 7, 30, 11, 24); // 2024/11/30 金曜 12:00:00
}

void loop()
{
    rtc.refresh();

    Serial.print("RTC Time: ");
    Serial.print(rtc.year());
    Serial.print('/');
    Serial.print(rtc.month());
    Serial.print('/');
    Serial.print(rtc.day());

    Serial.print(" (");
    Serial.print(daysOfTheWeek[rtc.dayOfWeek() - 1]);
    Serial.print(") ");

    Serial.print(rtc.hour());
    Serial.print(':');
    Serial.print(rtc.minute());
    Serial.print(':');
    Serial.println(rtc.second());

    Serial.print("RTC Temperature: ");
    Serial.print(rtc.temp() / 100);
    Serial.print("\xC2\xB0");
    Serial.println("C");

    Serial.println();
    delay(1000);
}