#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Constructor LCD 16x2
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Servo name_servo;
int servo_position = 0;
int LEDPin = 7;
int fotos;
int time_interval = 400; // ASSUMING THE GOPRO DOES A PHOTO EVERY 2 SECONDS, FOR EVERY DEGREE TURNED IT MAKES 4 PHOTOS. CHANGE THIS VALUE DEPENDING ON THE RELATION SPEED/PHOTOS YOU WANT.

// Setup

void setup() {
  // Define LED
  pinMode(LEDPin, OUTPUT);
  // Inicialice Servo
  name_servo.attach(4);
  // Indicate the library we are using a 16x2
  lcd.begin(16, 2);
  // Move the cursor to the (0, 0) position
  lcd.home ();
  // Write on the LCD
  lcd.print("   TIME LAPSE");
  // Move the cursor to the (0, 1) position
  lcd.setCursor ( 0, 1 );
  // Write on the LCD
  lcd.print("  Dani Navarro");
  // Light the LED
  digitalWrite(LEDPin, HIGH);
  // Wait for a couple seconds
  delay(2000);
  digitalWrite(LEDPin, LOW);
  
}

void loop() {
  // Servo turning from 0 to 180 degrees
 for (servo_position=0; servo_position <=180; servo_position +=1){
    // Update the number of photos made
    fotos = (servo_position*2);
    // Update the LCD
    lcd.clear();
    // Write on the LCD
    name_servo.write(servo_position);
    lcd.print("TURNING... ");
    lcd.print(servo_position);
    lcd.print((char)223);
    lcd.setCursor ( 0, 1 );
    lcd.print("N PHOTOS:  ");
    lcd.print(fotos);
    delay(time_interval);
      }
  // Servo turning from 180 to 0 degrees
  for (servo_position=180; servo_position >=0; servo_position -=1){
    // Update the number of photos made
    fotos = ((servo_position*((time_interval/100)/2)) + ((180-servo_position)*(time_interval/100)));
    // Update the LCD
    lcd.clear();
    name_servo.write(servo_position);
    lcd.print("TURNING... ");
    lcd.print(servo_position);
    lcd.print((char)223);
    lcd.setCursor ( 0, 1 );
    lcd.print("N PHOTOS:  ");
    lcd.print(fotos);
    delay(time_interval);
      }
 }
