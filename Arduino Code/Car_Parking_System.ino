#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Initialize LCD and Servo objects
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change the HEX address if necessary
Servo myservo1;

// Define IR sensor pins
const int IR1 = 8;`
const int IR2 = 12;

// Define the total number of parking slots
int totalSlots = 4;
int availableSlots = totalSlots;

// Flags for IR sensors
bool carEntering = false;
bool carExiting = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Set IR sensor pins as input
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  // Attach the servo to pin 3 and set initial position
  myservo1.attach(3);
  myservo1.write(100);

  // Display initial message on the LCD
  lcd.setCursor(0, 0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYSTEM ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Check for car entering
  if (digitalRead(IR1) == LOW && !carEntering) {
    delay(50);  // Small delay to debounce
    if (digitalRead(IR1) == LOW) {  // Confirm the reading
      carEntering = true;
      if (availableSlots > 0) {
        myservo1.write(0);  // Open gate
        availableSlots -= 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Car Entered ");
        delay(3000);  // Keep gate open for a while
        myservo1.write(100);  // Close gate
        lcd.clear();
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("    SORRY :(    ");
        lcd.setCursor(0, 1);
        lcd.print("  Parking Full  ");
        delay(3000);
        lcd.clear();
      }
    }
  }

  // Check for car exiting
  if (digitalRead(IR2) == LOW && !carExiting) {
    delay(50);  // Small delay to debounce
    if (digitalRead(IR2) == LOW) {  // Confirm the reading
      carExiting = true;
      if (availableSlots < totalSlots) {
        myservo1.write(0);  // Open gate
        availableSlots += 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Car Exited ");
        delay(3000);  // Keep gate open for a while
        myservo1.write(100);  // Close gate
        lcd.clear();
      }
    }
  }

  // Reset flags after sensors are no longer triggered
  if (carEntering) {
    if (digitalRead(IR1) == HIGH) {  // Wait for sensor to reset
      carEntering = false;
    }
  }

  if (carExiting) {
    if (digitalRead(IR2) == HIGH) {  // Wait for sensor to reset
      carExiting = false;
    }
  }

  // Display welcome message and available slots
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1);
  lcd.print("Slots Left: ");
  lcd.print(availableSlots);

  // Debugging information
  Serial.print("IR1: ");
  Serial.print(digitalRead(IR1));
  Serial.print(" IR2: ");
  Serial.print(digitalRead(IR2));
  Serial.print(" Slots: ");
  Serial.println(availableSlots);
}
