import serial
import pyttsx3

# Replace COM5 with your board's COM port
ser = serial.Serial('COM5', 115200)
engine = pyttsx3.init()
while True:
    line = ser.readline().decode(errors='ignore').strip()
    if "Bus Info" in line:
        print(line)
        engine.say(line)
        engine.runAndWait()
