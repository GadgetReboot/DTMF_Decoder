// MT8870 DTMF Decoder Demo
// Target Hardware:  Uno
//
// MT8870 Pin         Uno Pin
//   Q1                  2
//   Q2                  3
//   Q3                  4
//   Q4                  5
//   StD                 6
//
// Tested with Arduino IDE 1.8.13
// Gadget Reboot
// https://www.youtube.com/gadgetreboot

// input pins from MT8870
const byte Q1 = 2;
const byte Q2 = 3;
const byte Q3 = 4;
const byte Q4 = 5;
const byte StD = 6;

void setup() {
  Serial.begin(9600);

  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
  pinMode(StD, INPUT);
}

void loop() {

  // StD (delayed steering) output from MT8870 is high while a DTMF signal is present, low when not
  // when a DTMF tone pair is present, decode the key pressed (0-9, *, #)  A, B, C, D  are not decoded
  if (digitalRead(StD)) {
    uint8_t dtmf = ( 0x00 | (digitalRead(Q1) << 0) | (digitalRead(Q2) << 1) | (digitalRead(Q3) << 2) | (digitalRead(Q4) << 3) );
    switch (dtmf)
    {
      case 0x01:
        Serial.println("DTMF: 1");
        break;
      case 0x02:
        Serial.println("DTMF: 2");
        break;
      case 0x03:
        Serial.println("DTMF: 3");
        break;
      case 0x04:
        Serial.println("DTMF: 4");
        break;
      case 0x05:
        Serial.println("DTMF: 5");
        break;
      case 0x06:
        Serial.println("DTMF: 6");
        break;
      case 0x07:
        Serial.println("DTMF: 7");
        break;
      case 0x08:
        Serial.println("DTMF: 8");
        break;
      case 0x09:
        Serial.println("DTMF: 9");
        break;
      case 0x0A:
        Serial.println("DTMF: 0");
        break;
      case 0x0B:
        Serial.println("DTMF: *");
        break;
      case 0x0C:
        Serial.println("DTMF: #");
        break;
    }
    while (digitalRead(StD)) {};  // wait for current dtmf signal to end before looking for the next one
  }
}
