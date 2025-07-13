#include <IRremote.h>
#include <Servo.h>

#define IR_RX_PIN 11  
Servo myServo;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RX_PIN);
  myServo.attach(9);  
  myServo.write(0);   
  Serial.println("Ready to receive IR commands...");
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t irCode = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("Received HEX: 0x");
    Serial.println(irCode, HEX);  

    // Map buttons to servo angles (0°-180° in 20° steps)
    if (irCode == 0xF30CFF00) {   // Button "1"
      myServo.write(0);
      Serial.println("1 → 0°");
    }
    else if (irCode == 0xE718FF00) {  // Button "2"
      myServo.write(20);
      Serial.println("2 → 20°");
    }
    else if (irCode == 0xA15EFF00) {  // Button "3"
      myServo.write(40);
      Serial.println("3 → 40°");
    }
    else if (irCode == 0xF708FF00) {  // Button "4"
      myServo.write(60);
      Serial.println("4 → 60°");
    }
    else if (irCode == 0xE31CFF00) {  // Button "5"
      myServo.write(90);
      Serial.println("5 → 90°");
    }
    else if (irCode == 0xA55AFF00) {  // Button "6"
      myServo.write(120);
      Serial.println("6 → 120°");
    }
    else if (irCode == 0xBD42FF00) {  // Button "7"
      myServo.write(140);
      Serial.println("7 → 140°");
    }
    else if (irCode == 0xAD52FF00) {  // Button "8"
      myServo.write(160);
      Serial.println("8 → 160°");
    }
    else if (irCode == 0xB54AFF00) {  // Button "9"
      myServo.write(180);
      Serial.println("9 → 180°");
    }

    IrReceiver.resume();  // Ready for next signal
    delay(100);
  }
}