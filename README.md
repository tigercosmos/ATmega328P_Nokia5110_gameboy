# ATmega328P Nokia5110 Gameboy
DIY Handheld Game Console Made With ATmega328P and Nokia5110 LCD.

## Game Process
- welcome
- menu
    - snake game
        - win the game and turn back to the menu
        - lose the game and turn back to the menu
    - shoot game (not finished yet)

## Build Project
```
git clone https://github.com/tigercosmos/ATmega328P_Nokia5110_gameboy.git
```
Open project via `AtmelStudio 7` and click `Build solution`.

## Firmware
Program the `hex` code into Atmega328P via `AVRDUDESS 2.4`

## Enviroment
Sofeware: 
- Windows 10
- AtmelStudio 7
- AVRDUDESS 2.4 (avrdude version 6.1)

Hardware:
- ATmega328P
- Arduino UNO (ISP)
- Nokia5110 LCD
- BJT
- Buttons
- Buzzer
- Resistance
- Wires
- 220u Capacitance

## Photo 
![](https://github.com/tigercosmos/ATmega328P_Nokia5110_gameboy/raw/master/assets/device.jpg)

## Vedio 
You can see the DEMO via the [LINK](https://www.dropbox.com/s/jr5x41fuszlm30k/ATmega328P_Nokia5110_gameboy.mov?dl=0).

## Circuit Diagram
![](https://raw.githubusercontent.com/tigercosmos/ATmega328P_Nokia5110_gameboy/master/assets/circuit_diagram.png)
### Nokia 5110
- SCE PB1
- RST PB2
- DC PB3
- DIN PB4
- CLK PB5
### Buzz
- PC5
### Buttons
- RIGHT PD5
- DOWN PD4
- UP PD3
- LEFT PD2
- FIRE PD6
- CTRL PD7

## Tools
The `tools` folder includes `FastLCD` software which can help you build image btyes easier.