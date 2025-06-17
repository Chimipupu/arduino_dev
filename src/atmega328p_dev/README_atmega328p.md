# ATmega328p評価F/W開発
ATmega328pの評価F/Wのブランチ

## 開発環境

- 📍基板
  - 📍ATmega328p
    - 📍Arduino Uno Rev.3
    - 📍Arduino Nano
    - 📍Arduino pro mini

  - 📍LGT8F328P
    - 📍MiniEVB

## 実装機能

- 📍UART
  - ✅115200 8N1 ... デバッグ用
- 📍タイマー⏰
  - ⚠️タイマー0(8bit)⏰ ... ⚠️予約済み（Arduino IDE）
  - ✅タイマー1(16bit)⏰ ... 1000㎳インターバル
  - ✅タイマー2(8bit)⏰ ... 8.128msインターバル
- 📍GPIO
  - ✅GPIO 13 ... 基板実装のLED

- 📍割込み（ISR）
  - ⚠️タイマー0⏰（TIMER0_COMPA_vect）
    - ⚠️予約済み（Arduino IDE）
  - ✅タイマー1⏰（TIMER1_COMPA_vect）
  - ✅タイマー2⏰（TIMER2_COMPA_vect）
