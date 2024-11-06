# AVRマイコン評価F/W開発 by ちみ
AVRマイコンの評価F/Wの個人開発リポジトリ🥳

## 実装機能

- 📍S/W(アプリ)
  - ✅7セグLED制御機能（74HC595）
    - ✅ダイナミック点灯
    - ✅数値から7セグ4桁に変換

- 📍H/W(ハードウェア)
  - UART
    - ✅文字をシリアル出力
  - 割込み（ISR）
    - タイマー⏰
      - タイマー1割込み（TIMER1_COMPA_vect）
        - ✅変数インクリメント

## 開発環境
- MCU : ATmega328p
  - CPU : AVR
  - 命令長 : 8bit
  - Clock : 16MHz
  - ROM : 32KB
  - RAM : 2KB
  - EEPROM : 1KB
  - GPIO : x23
  - PWM : x6ch
  - UART : x1ch
  - SPI : x1ch
  - I2C : x1ch
  - ADC : 10bit x8ch
  - DAC : N/A
  - Timer
    - 8bit : x2ch
    - 16bit : x1ch
  - WDT : 1