# 🚌 Bus Stop Alert System for Visually Impaired (Wi-Fi Based)

## 📘 Project Overview
This project provides *bus arrival alerts for visually impaired people* without using RFID.  
Each bus is equipped with a *Wi-Fi hotspot (ESP / SiWG917 board)* that broadcasts the bus details.  
When a passenger’s phone connects to the bus hotspot, it automatically displays or reads out the *bus number, route, and upcoming stop*.

---

## ⚙️ System Workflow

1. The *Wi-Fi module (ESP8266 / SiWG917)* acts as a hotspot and web server.  
   - SSID: Bus_Hotspot  
   - Password: busalert1

2. The module hosts a web page at [http://192.168.4.1](http://192.168.4.1) that shows:
   - 🚌 Bus number  
   - 📍 Route details  
   - ⏭️ Upcoming bus stop  

3. When a visually impaired user’s phone connects to the hotspot:
   - The information is displayed in a simple interface.  
   - Voice output (TTS) announces the bus information.

---

## 🧠 Features
- Works *without RFID* — purely Wi-Fi based.
- Low-cost and easily deployable on any bus.
- Can announce bus info through speech (Text-to-Speech).
- Supports multiple buses (each board can have unique info).
- Helpful for visually impaired and general passengers.

---

## 🧩 Components Used
| Component | Description |
|------------|-------------|
| *SiWG917 / ESP8266 Board* | Acts as Wi-Fi hotspot and local web server |
| *Python (optional)* | Reads serial data and converts it to voice |
| *Android App (Kotlin)* | Displays and speaks bus info (future stage) |

---

## 💻 Code Files
| File | Purpose |
|------|----------|
| main.c | Runs on the Wi-Fi module. Creates hotspot and shows bus info. |
| serial_tts.py | Python script for speech output using PC serial data. |
| README.md | Project documentation. |

---

## 🚀 How to Run

### 🧠 For the Embedded Board
1. Open main.c in *Simplicity Studio* (for SiWG917) or Arduino IDE (for ESP8266).  
2. Flash the code to your board.  
3. Open the Serial Monitor (baud: 115200).  
4. The output will show:
5. On your mobile, connect to Bus_Hotspot.
6. Open a browser → visit [http://192.168.4.1](http://192.168.4.1) → bus info appears!

---

### 🗣️ For Voice Output 
1. Connect your board to the PC via USB.  
2. Run serial_tts.py:
```bash
python serial_tts.py
Bus Info: 23B | Route: Gandhipuram → Peelamedu → Airport | Next Stop: Peelamedu
