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

extern uint32_t g_cnt;

// タイマー1 割込みハンドラISR
ISR(TIMER1_COMPA_vect)
{
    g_cnt++;
    if (g_cnt >= 10000) {
        g_cnt = 0;
    }
}

void drv_timer_init(void)
{
    // タイマー1の設定
    __DI;
    TCCR1A = 0;  // タイマー1の制御レジスタAをクリア
    TCCR1B = 0;  // タイマー1の制御レジスタBをクリア
    TCNT1 = 0;   // タイマー1のカウンタをクリア

    // OCR1A = 78; // 5ms(= 78カウント)
    // OCR1A = 156;  // 10ms(= 156 カウント)
    // OCR1A = 1562;  // 100ms(= 1562 カウント)
    OCR1A = 15625;  // 1000ms(= 15625 カウント)

    TCCR1B |= (1 << WGM12); // CTC (Clear Timer on Compare Match) モード
    TCCR1B |= (1 << CS12) | (1 << CS10); // プリスケーラ1024
    TIMSK1 |= (1 << OCIE1A); // タイマー1比較Aマッチ割り込みを許可
    __EI;
}