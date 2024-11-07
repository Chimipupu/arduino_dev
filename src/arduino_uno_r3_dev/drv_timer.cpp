/**
 * @file drv_timer.cpp
 * @author ちみ/Chimi（https://github.com/Chimipupu）
 * @brief ATmega328p タイマーのドライバ
 * @version 0.1
 * @date 2024-11-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "drv_timer.hpp"
#include "mfs.hpp"

extern uint32_t g_cnt;

// タイマー0(16.320ms) 割込みハンドラISR
#if 0
ISR(TIMER0_COMPA_vect)
{
    // Arduinoが既にdelay()で使ってる
}
#endif

// タイマー1(100ms) 割込みハンドラISR
ISR(TIMER1_COMPA_vect)
{
    g_cnt++;
    if (g_cnt >= 10000) {
        g_cnt = 0;
    }
}

// タイマー2(8.128ms) 割込みハンドラISR
ISR(TIMER2_COMPA_vect)
{
    uint8_t btn_1 = digitalRead(MFS_BUTTON_S1_PIN);
    uint8_t btn_2 = digitalRead(MFS_BUTTON_S2_PIN);
    uint8_t btn_3 = digitalRead(MFS_BUTTON_S3_PIN);

    if ((btn_1 == 0) || (btn_2 == 0) || (btn_3 == 0)) {
        digitalWrite(MFS_LED_1_PIN, LOW);
        digitalWrite(MFS_LED_2_PIN, LOW);
        digitalWrite(MFS_LED_3_PIN, LOW);
        digitalWrite(MFS_LED_4_PIN, LOW);
    }else{
        digitalWrite(MFS_LED_1_PIN, HIGH);
        digitalWrite(MFS_LED_2_PIN, HIGH);
        digitalWrite(MFS_LED_3_PIN, HIGH);
        digitalWrite(MFS_LED_4_PIN, HIGH);
    }
}

void drv_timer_init(void)
{
    __DI;
    // タイマー0(8bit) ... インターバルタイマー設定(16.320ms)
#if 0 // Arduinoが既にdelay()で使ってる
    TCCR0A = 0;                // タイマー0の制御レジスタAをクリア
    TCCR0B = 0;                // タイマー0の制御レジスタBをクリア
    TCNT0 = 0;                 // タイマー0のカウンタをクリア
    OCR0A = 255 ;              // 16.320ms(= 255 カウント)
    TCCR0A |= (1 << WGM01);    // CTCモード
    TCCR0B |= (1 << CS02) | (1 << CS00);  // プリスケーラ1024
    TIMSK0 |= (1 << OCIE0A);   // タイマー0の比較Aマッチ割り込みを許可
#endif

    // タイマー1(16bit) ... インターバルタイマー設定(100ms)
    TCCR1A = 0;                // タイマー1の制御レジスタAをクリア
    TCCR1B = 0;                // タイマー1の制御レジスタBをクリア
    TCNT1 = 0;                 // タイマー1のカウンタをクリア
    // OCR1A = 78;                // 5ms(= 78 カウント)
    // OCR1A = 156;               // 10ms(= 156 カウント)
    // OCR1A = 1562;              // 100ms(= 1562 カウント)
    OCR1A = 15625;             // 1000ms(= 15625 カウント)
    TCCR1B |= (1 << WGM12);    // CTCモード
    TCCR1B |= (1 << CS12) | (1 << CS10); // プリスケーラ1024
    TIMSK1 |= (1 << OCIE1A);   // タイマー1の比較Aマッチ割り込みを許可

    // タイマー2(8bit) ... インターバルタイマー設定(8.128ms)
    TCCR2A = 0;                // タイマー2の制御レジスタAをクリア
    TCCR2B = 0;                // タイマー2の制御レジスタBをクリア
    TCNT2 = 0;                 // タイマー2のカウンタをクリア
    OCR2A = 127;               // 8.128ms(= 127 カウント)
    TCCR2A |= (1 << WGM21);    // CTCモード
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // プリスケーラ1024
    TIMSK2 |= (1 << OCIE2A);   // タイマー2の比較Aマッチ割り込みを許可
    __EI;
}