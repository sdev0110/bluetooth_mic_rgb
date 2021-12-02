/**********************************************************************
 Include Files
 *********************************************************************/
#include <Arduino.h>

/**********************************************************************
 Public Data
 *********************************************************************/
int sensorValue = 0;
int sensorPin = A0;
int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

/**********************************************************************
 Public Functions
 *********************************************************************/

/**********************************************************************
 Name: RGB_color

 Description:
  Writes the numerical representation of colors on designated
  RGB Pins

 Input Parameters:
  red_light_value - determines whether red LED is ON (255) or OFF (0)
  blue_light_value - determines whether blue LED is ON (255) or OFF (0)
  green_light_value - determines whether green LED is ON (255) or OFF (0)

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

/**********************************************************************
 Name: setup

 Description:
  Function that only executed at startup

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  RGB_color(255, 255, 255); // White
}

/**********************************************************************
 Name: loop

 Description:
  Function that is being executed repeatedly

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  Serial.print("sensor value: ");
  Serial.println(sensorValue);
  if (sensorValue > 15)
  {
    RGB_color(255, 0, 0); // Red
    delay(200);
    RGB_color(0, 255, 0); // Green
    delay(200);
    RGB_color(0, 0, 255); // Blue
    delay(200);
    RGB_color(255, 255, 125); // Raspberry
    delay(200);
    RGB_color(0, 255, 255); // Cyan
    delay(200);
    RGB_color(255, 0, 255); // Magenta
    delay(200);
    RGB_color(255, 255, 0); // Yellow
    delay(200);
    RGB_color(0, 0, 0); // White
    delay(200);
  }
  else
  {
    RGB_color(255, 255, 255); // White
    delay(300);
  }
}
