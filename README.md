**Two Ways to Control Servos: IR Remote (Digital) vs. Joystick (Analog)**  

This ReadME contains **two distinct Arduino projects** for servo motor control, demonstrating both digital and analog input methods. Choose either project or combine them for advanced applications!  

---

## **📂 Project 1: IR Remote Servo Controller**  
**Control servos with button presses from an IR remote (Digital Signal Project)**  

### **Features**  
- Use buttons **1-9** to set servo angles (0° to 180°)  
- HEX code decoding for any NEC IR remote  
- Serial monitor debugging  

### **Components**  
- Arduino Uno  
- IR Receiver (TSOP382)  
- Servo Motor (SG90)  

### **Wiring**  
| IR Receiver | Arduino |  
|------------|---------|  
| VCC        | 5V      |  
| GND        | GND     |  
| OUT        | D11     |  

| Servo      | Arduino |  
|------------|---------|  
| Signal     | D9      |  
| VCC        | 5V      |  
| GND        | GND     |  

Schematic
<img width="970" height="747" alt="Schematic" src="https://github.com/user-attachments/assets/5d26b5ef-7253-43f0-b5cd-8030680784e4" />



### **Code Highlights**  
```cpp
#include <IRremote.h>
#include <Servo.h>

void setup() {
  IrReceiver.begin(11); // IR on D11
  myServo.attach(9);    // Servo on D9
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t code = IrReceiver.decodedIRData.decodedRawData;
    if (code == 0xF30CFF00) myServo.write(0); // Button 1 → 0°
    IrReceiver.resume();
  }
}
```

---

## **📂 Project 2: Analog Joystick Servo Controller**  
**Precisely control servos with a 2-axis joystick (Analog Signal Project)**  

### **Features**  
- Smooth 180° servo movement via potentiometer inputs  
- X/Y axis independent control  
- Built-in deadzone for stability  

### **Components**  
- Arduino Uno  
- Analog Joystick (KY-023)  
- 2x Servo Motors (SG90)  

### **Wiring**  
| Joystick | Arduino |  
|----------|---------|  
| VCC      | 5V      |  
| GND      | GND     |  
| VRX      | A0      |  
| VRY      | A1      |  

| Servo X   | Arduino |  
|-----------|---------|  
| Signal    | D9      |  
| VCC       | 5V      |  
| GND       | GND     |  

| Servo Y   | Arduino |  
|-----------|---------|  
| Signal    | D10     |  
| VCC       | 5V      |  
| GND       | GND     |  


Circuit Diagram in WOKWI
<img width="924" height="633" alt="لقطة شاشة 2025-07-14 042657" src="https://github.com/user-attachments/assets/671b7d06-1975-4faf-a5b3-0904f5f69aee" />


### **Code Highlights**  
```cpp
#include <Servo.h>
Servo xServo, yServo;

void setup() {
  xServo.attach(9);  // X-axis on D9
  yServo.attach(10); // Y-axis on D10
}

void loop() {
  int xAngle = map(analogRead(A0), 0, 1023, 0, 180);
  xServo.write(xAngle); // X-axis control
}
```

---

## **📚 Key Differences**  
| Feature          | IR Remote Project (Digital) | Joystick Project (Analog) |  
|-----------------|----------------------------|--------------------------|  
| **Signal Type** | Digital (HEX codes)         | Analog (0-1023 values)   |  
| **Precision**  | Fixed positions             | Continuous movement      |  
| **Best For**   | Preset actions              | Real-time control        |  
| **Complexity** | Easy (button mapping)       | Moderate (calibration)   |  

---

## **⚡ Quick Start**  
1. **For IR Control**:  
   - Upload `IR_Servo.ino`  
   - Press buttons 1-9 to test  

2. **For Joystick Control**:  
   - Upload `Joystick_Servo.ino`  
   - Move joystick to see servo response  

---

## **🚀 Upgrade Ideas**  
- **Combine Both**: Use joystick for manual control + IR buttons for presets  
- **Add LCD**: Display current angle/mode  
- **Wireless**: Replace joystick with Bluetooth module  

---

## **⚠️ Troubleshooting**  
| Issue               | IR Solution               | Joystick Solution         |  
|---------------------|--------------------------|--------------------------|  
| No response         | Check remote batteries    | Test potentiometers with multimeter |  
| Servo jitter       | Add 100µF capacitor      | Implement software deadzone |  
| Wrong movements    | Verify HEX codes          | Calibrate `map()` ranges |  

---

**🎓 Learning Outcomes**:  
- Digital vs. analog signal processing  
- Servo motor control techniques  
- Real-world input device integration  

Choose your preferred method or experiment with both! Let us know which project you're building. 🛠️
