{
  "version": 1,
  "author": "Akshansh",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-uno", "id": "uno", "top": 0, "left": 0, "attrs": {} },
    {
      "type": "wokwi-hc-sr04",
      "id": "ultrasonic1",
      "top": -180.9,
      "left": 82.3,
      "attrs": { "distance": "116" }
    },
    {
      "type": "wokwi-led",
      "id": "led1",
      "top": -118.8,
      "left": -44.2,
      "attrs": { "color": "yellow" }
    },
    {
      "type": "wokwi-led",
      "id": "led2",
      "top": -118.8,
      "left": 42.2,
      "attrs": { "color": "red" }
    },
    {
      "type": "wokwi-led",
      "id": "led3",
      "top": -118.8,
      "left": -5.8,
      "attrs": { "color": "limegreen" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r1",
      "top": 80.75,
      "left": 297.6,
      "attrs": { "value": "220" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r2",
      "top": 42.35,
      "left": 288,
      "attrs": { "value": "220" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r3",
      "top": 147.95,
      "left": 307.2,
      "attrs": { "value": "220" }
    },
    {
      "type": "wokwi-buzzer",
      "id": "bz1",
      "top": -199.2,
      "left": 299.4,
      "attrs": { "volume": "0.1" }
    },
    {
      "type": "wokwi-lcd1602",
      "id": "lcd1",
      "top": -118.4,
      "left": 370.4,
      "attrs": { "pins": "i2c" }
    }
  ],
  "connections": [
    [ "ultrasonic1:VCC", "uno:5V", "red", [ "v0" ] ],
    [ "ultrasonic1:GND", "uno:GND.1", "black", [ "v0" ] ],
    [ "ultrasonic1:TRIG", "uno:3", "green", [ "v0" ] ],
    [ "ultrasonic1:ECHO", "uno:2", "green", [ "v0" ] ],
    [ "bz1:2", "uno:7", "green", [ "v0" ] ],
    [ "bz1:1", "uno:GND.1", "green", [ "v0" ] ],
    [ "led1:C", "uno:GND.2", "green", [ "v0" ] ],
    [ "led3:C", "uno:GND.2", "green", [ "v0" ] ],
    [ "led2:C", "uno:GND.2", "green", [ "v0" ] ],
    [ "led3:A", "r2:1", "green", [ "v0" ] ],
    [ "r2:2", "uno:4", "green", [ "v0" ] ],
    [ "led2:A", "r3:1", "green", [ "v0" ] ],
    [ "r3:2", "uno:6", "green", [ "v0" ] ],
    [ "led1:A", "r1:1", "green", [ "v0" ] ],
    [ "r1:2", "uno:5", "green", [ "v0" ] ],
    [ "lcd1:GND", "uno:GND.1", "black", [ "h-259.2", "v96" ] ],
    [ "lcd1:VCC", "uno:5V", "red", [ "h-211.2", "v268.9" ] ],
    [ "lcd1:SDA", "uno:A4", "green", [ "h-124.8", "v259.4" ] ],
    [ "lcd1:SCL", "uno:A5", "green", [ "h0" ] ]
  ],
  "dependencies": {}
}