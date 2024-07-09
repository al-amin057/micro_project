# Introduction
The automated car parking system aims to streamline parking management using microprocessor and microcontroller technology. The system automates the detection of parking space availability and controls a gate mechanism to manage vehicle entry.

# Components and Their Functions

- **Arduino UNO:** The central microcontroller that processes sensor inputs and controls the servo motor.
- **IR Proximity Sensors:** Used to detect the presence of vehicles in parking spaces. One sensor detects entry, and another detects the occupation of the parking space.
- **16x2 LCD i2c Display:** Displays the status of the parking space, whether it is available or occupied.
- **Servo Motor:** Controls the gate mechanism to allow or restrict vehicle entry based on sensor inputs.

# How It Works

1. **Initialization:** The Arduino initializes the servo motor and the LCD display.
2. **Sensor Reading:** Continuously reads the state of the IR sensors to detect the presence or absence of vehicles.
3. **Display Update:** Updates the LCD display with the status of the parking space (Available or Occupied).
4. **Gate Control:** Opens the gate if the parking space is available and closes it when the space is occupied.

# Circuit Diagram:
![image](https://github.com/al-amin057/micro_project/assets/104164316/4982a980-e33d-411f-b687-7b5e326990f5)


# <u>Steps to Set Up the Project</u>

## 1. Gather Components
To begin, you need to gather all the necessary hardware components for the project. These include:
- Arduino UNO: The main microcontroller that will be used to process inputs and control outputs.
- IR Proximity Sensor: This sensor will detect the presence of a vehicle in the parking space.
- 16x2 LCD i2c Display: This display will show the status of the parking space, such as "Parking Available" or "Parking Full".
- Servo Motor: The servo motor will act as a gate, opening and closing based on the parking space status.
- Jumpers: These are used to make the electrical connections between the components and the Arduino.
  
**N.B. Ensure that all components are in working condition before proceeding to the next step.**


## 2. Circuit Assemble

Next, you need to assemble the circuit by connecting the components to the Arduino UNO. Follow the provided schematic diagram carefully:

1. **IR Proximity Sensor:**
    - Connect the VCC pin to the 5V pin on the Arduino.
    - Connect the GND pin to the GND pin on the Arduino.
    - Connect the signal pin to a digital pin on the Arduino (e.g., D2).
2. **16x2 LCD i2c Display:**
    - Connect the VCC pin to the 5V pin on the Arduino.
    - Connect the GND pin to the GND pin on the Arduino.
    - Connect the SDA pin to the A4 pin on the Arduino.
    - Connect the SCL pin to the A5 pin on the Arduino.
3. **Servo Motor:**
    - Connect the VCC pin to the 5V pin on the Arduino.
    - Connect the GND pin to the GND pin on the Arduino.
    - Connect the signal pin to a PWM-capable digital pin on the Arduino (e.g., D9).
4. **Jumpers:**
    - Use the jumpers to make the above connections secure and reliable.
  

**N.B. Double-check all connections to ensure they are correct and secure.**

## 3. Code Development

With the hardware set up, the next step is to write the Arduino code to control the components. Open the Arduino IDE and write a sketch (program) that performs the following tasks:
- Initialize the LCD display and servo motor.
- Continuously read the input from the IR Proximity Sensor.
- Update the LCD display with the current parking status based on the sensor input.
- Control the servo motor to open or close the gate depending on whether the parking space is available or full.
  
Here is the code of my project:
```cpp
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
```


