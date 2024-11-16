# ATmega328p評価F/W開発 by ちみ
ATmega328pの評価F/Wのブランチ🥳

## 開発環境
- 📍基板
  - 📍ATmega328p
    - 📍Arduino Uno Rev.3
    - 📍Arduino Nano
    - 📍Arduino pro mini

## 実装機能

- 📍UART
  - ✅文字をシリアル出力
- 📍タイマー⏰
  - ❌タイマー0(8bit)⏰ ... 未使用
  - ✅タイマー1(16bit)⏰ ... 1000㎳インターバル
  - ✅タイマー2(bit)⏰ ... 8.128msインターバル
- 📍GPIO
  - ✅GPIO 13 ... 基板実装のLED

- 📍割込み（ISR）
  - ❌タイマー0⏰（TIMER0_COMPA_vect）
    - ❌未使用
  - ✅タイマー1⏰（TIMER1_COMPA_vect）
    - ✅1秒カウント
  - ✅タイマー2⏰（TIMER2_COMPA_vect）
    - ✅ボタン監視