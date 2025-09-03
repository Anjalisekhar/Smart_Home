# Smart Home System

## Objective
Design a Smart Home System controllable via Push Buttons (Manual), Remote Control, Bluetooth, and Wi-Fi.

## Description
This project demonstrates a smart home environment using an **STM32F405RGT6 development board**. DC LED bulbs and a DC motor simulate home appliances such as lights and fans. Users can control these appliances through:

- Push Buttons (Manual Control)
- IR Remote Control
- Bluetooth App
- Wi-Fi Dashboard

Appliance statuses are displayed on an **LCD**. The system includes user authentication with User ID and security codes stored in **SPI-EEPROM**.

---

## Hardware Required
- CORTEX M4-STM32F405 Development Board  
- DC LED Bulb (Room Light Simulation)  
- DC Motor (Ceiling Fan Simulation)  
- Push Buttons  
- IR Remote & Receiver Module  
- Dual Motor Driver  
- 5V 2A Power Supply with DC Plug & Adapter Plate  
- 12V Battery  
- Relay Module  
- LEDs  
- 4x4 Matrix Keypad  
- HC-05 Bluetooth Module  
- ESP-015 Wi-Fi Module  

---

## Software Required
- STM32F405RGT6 Development IDE  
- Serial Bluetooth Terminal (Android App)  
- IoT Dashboard Platforms  

---

## Features

### Security
1. **Power On:** LCD displays "Welcome".  
2. **Authentication:** User presses `*` → enters User ID (1–5) → `#`.  
3. **Security Code:** LCD prompts for 4-digit code → `#` to confirm.  
4. **Code Verification:**  
   - If correct → "Access Granted" (GREEN LED ON) → Menu displayed  
   - If incorrect → "Access Denied" (RED LED ON) → retry  

**Menu Options:**
- **Password Change:** Enter new code → saved in SPI-EEPROM  
- **Enter System:** Proceed to main functionalities  

---

### Main System Functionality

#### 1. Manual Control (Push Buttons)
- Button 1 → Light ON/OFF  
- Button 2 → Fan ON/OFF  

#### 2. Remote Control
- **Power Button:** Toggle Light/Fan  
- **Mode Button:** Select Light or Fan Mode  
- **Fan Mode:**  
  - Play/Pause → Start/Stop  
  - Button 1 → 30% Speed  
  - Button 2 → 50% Speed  
  - Button 3 → 80% Speed  
- **Light Mode:**  
  - Play/Pause → ON/OFF  
  - Button 1 → 30% Brightness  
  - Button 2 → 50% Brightness  
  - Button 3 → 80% Brightness  

#### 3. Bluetooth Control
- Button 1 → Light ON/OFF  
- Button 2 → Fan ON/OFF  

#### 4. Wi-Fi Control
- Button 1 → Light ON/OFF  
- Button 2 → Fan ON/OFF  
