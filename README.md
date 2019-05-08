# arduino-echoboy-midi-controller
Project of USB-MIDI controller for [EchoBoy](https://www.soundtoys.com/product/echoboy/) (delay effect VST) based on [Arduino Mega 2560](https://www.arduino.cc/en/Guide/ArduinoMega2560).

## Content

1. Overview
2. Layout
3. Electrical calculations
3. Needed parts
4. PCB connections
5. Soldering
6. Testing
7. Code (ready)
8. Box preparation

## Prototype

I turned dreams into reality. No one produces such a machine, so I made it myself from scratch.

After 4 months of soldering, programming, drilling - working prototype is done.

This machine is built based on Arduino Mega 2560, a lot of expanders and AD converters.

Photos of last final steps are listed below. 

### Prototype front panel vision

![FrontPanelVision](images/0.png?raw=true "FrontPanelVision")

### Working prototype with extra features like "Sync 1-2 echo time" or "Set Midi all".

Also LCD screen inform us about last values of time/note for Echo 1 & 2.

![FrontPanel](images/1.jpg?raw=true "FrontPanel")

### Back panel

Back side with DIP 4-channel switch to choose MIDI channel. Power switch on the right side.

![BackPanel](images/2.jpg?raw=true "BackPanel")

### Mounting inside box

![MountingBox](images/3.jpg?raw=true "MountingBox")

### Soldering & testing process 

Stress memory test on Arduino Uno R3 - which fails, so then I needed Arduino Mega to handle that.

![MemoryTests](images/4.jpg?raw=true "MemoryTests")