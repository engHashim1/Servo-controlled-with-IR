# Servo-controlled-with-IR
Control a servo motor with an IR remote using Arduino. Press buttons 1-9 to move the servo to preset angles (0°-180°). Includes HEX code mapping and easy wiring.


📌 Features

    ✅ Remote-controlled servo using IR signals

    🔢 Buttons 1-9 map to angles (0°, 20°, 40°, ..., 180°)

    🔍 Serial Monitor debugging (shows HEX codes & servo angles)

    🛠️ Easy wiring (only 3 components needed)

    🔄 Customizable (supports any NEC IR remote)

🛠 Hardware Needed
Component	Quantity
Arduino (Uno/Nano)	1
IR Receiver (TSOP382/VS1838)	1
Servo Motor (SG90)	1
Breadboard & Jumper Wires	As needed
🔌 Wiring Diagram
IR Receiver	Arduino
VCC	5V
GND	GND
OUT	D11
Servo Motor	Arduino
VCC (Red)	5V
GND (Brown)	GND
SIG (Yellow)	D9 (PWM)
💻 Code Setup

    Install the IRremote library

        Arduino IDE → Sketch → Include Library → Manage Libraries → Search for "IRremote" by shirriff → Install.

    Upload the code

    CODE

    #include <IRremote.h>
    #include <Servo.h>

    #define IR_PIN 11  // IR receiver on D11
    Servo myServo;

    void setup() {
      Serial.begin(9600);
      IrReceiver.begin(IR_PIN);
      myServo.attach(9);  // Servo on D9
    }

    void loop() {
      if (IrReceiver.decode()) {
        uint32_t irCode = IrReceiver.decodedIRData.decodedRawData;
        
        // Button-to-angle mapping (customize your HEX codes)
        if (irCode == 0xF30CFF00) myServo.write(0);     // Button 1 → 0°
        else if (irCode == 0xE718FF00) myServo.write(20); // Button 2 → 20°
        // ... Add more buttons (up to 9 → 180°)
        
        IrReceiver.resume();  // Ready for next signal
      }
      delay(100);
    }

    Find your remote's HEX codes

        Use the IRrecvDumpV2 example (File > Examples > IRremote > IRrecvDumpV2) to detect button codes.

🚀 How It Works

    Press a button (e.g., "1") on the IR remote.

    The IR receiver captures the signal and sends it to Arduino.

    Arduino decodes the HEX value and moves the servo to the assigned angle.

    The Serial Monitor shows real-time feedback.

🔧 Troubleshooting
Issue	Solution
Servo doesn’t move	Check wiring + remote batteries
Wrong angles	Update HEX codes in the if-else
Jittery servo	Add a 100µF capacitor to servo


🎯 Extensions

    Add more servos (e.g., pan-tilt mechanism).

    Use an LCD screen to display the angle.

    Combine with a distance sensor for object tracking.

📜 License

MIT License - Free for personal and educational use.

Happy tinkering! 🛠️🚀
