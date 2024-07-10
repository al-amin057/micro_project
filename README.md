<div align="center">
<h1>Shahjalal University of Science and Technology, Sylhet </h1><br>
Department of <br>
<h2>Computer Science & Engineering</h2>

 
![image](https://github.com/al-amin057/micro_project/assets/104164316/b8b92d25-1952-4323-9200-d9c535655aa4)


</div>
<div>
Course Name: <b>Microprocessor and Interfacing Lab</b> <br>
Course Code: <b>CSE-368</b> <br>
Group: <b>07</b><br>
Project Title: <b>Automated Car Parking System</b>

## Team Members
1. Al-Amin (**2020331057**)
2. Md. Sakib Hassan (**2020331109**)
3. Mahmudul Ferdous (**2020331037**)
4. Riaz Ahmed (**2020331079**)
5. MD Rafi  (**2019331096**)
</div>



# Automated Car Parking System
Al-Amin Hossain 
<br>
Department of Computer Science and Engineering, Shahjalal University of Science and Technology, Sylhet
3114, Bangladesh
<hr>
<p align = "justify">We are pleased to present our project, completed under the guidance of <a href = "https://www.sust.edu/d/cse/faculty-profile-detail/859">Abdullah Al Noman</a> Sir, Lecturer, department of Computer Science & Engineering, SUST, as part of the "Microprocessor and Interfacing Lab" course (Course Code: CSE-368). Our team, Group 07, consisting of five members, has diligently worked on this project, combining our skills and knowledge to achieve the objectives set forth in this course. We are excited to share our findings and the outcomes of our hard work. </p>
Here is our Project <a href="https://github.com/al-amin057/micro_project/blob/main/Project%20Proposal.pdf">Proposal Document</a>. Today we are presenting our project. <hr>


![image](https://github.com/al-amin057/micro_project/assets/104164316/6663a377-93a7-4840-bc3e-fe63bb02c0e0)


# Abstract
<div align = "justify">The automated car parking system aims to streamline parking management using microprocessor and microcontroller technology. The system automates the detection of parking space availability and controls a gate mechanism to manage vehicle entry.
</div>

# Introduction
<div align = "justify">This project presents an Automated Car Parking System using an Arduino UNO microcontroller. The system is designed to streamline the process of vehicle entry and exit in parking facilities by automating gate control and parking space management. It employs IR Proximity Sensors to detect vehicle presence, a 16x2 LCD i2c Display to show real-time parking status, and a Servo Motor to control the gate. The Arduino processes the sensor inputs to update the parking availability displayed on the LCD and to manage the gate's opening and closing actions. This project aims to provide an efficient and user-friendly solution for managing parking spaces, reducing human intervention, and enhancing overall parking efficiency. The system can be scaled and modified to accommodate various parking lot sizes and configurations, making it a versatile tool for modern parking management.
</div>

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

# Circuit Diagram
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

Clone the repository:
```bash
https://github.com/al-amin057/micro_project.git
cd micro_project
```
Here is the explanation of <a href="https://github.com/al-amin057/micro_project/blob/main/Arduino%20Code/Car_Parking_System.ino">Arduino Code/Car_Parking_System.ino</a>:
1. Libraries and Definitions
   ```cpp
   #include <Wire.h>
   #include <LiquidCrystal_I2C.h>
   #include <Servo.h>
   ```
   - Wire.h and LiquidCrystal_I2C.h are included for I2C communication with the LCD.
   - Servo.h is included to control the servo motor.
     
2. LCD and Servo Initialization
   ```cpp
   LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize LCD with I2C address
   Servo myservo1;
   ```
   - The LCD is initialized with an I2C address of 0x27 and dimensions of 16 columns and 2 rows.
   - A Servo object is created for controlling the servo motor.
   - 
3. IR Sensor and Slot Definitions
   ```cpp
   const int IR1 = 8;
   const int IR2 = 12;
   int totalSlots = 4;
   int availableSlots = totalSlots;
   bool carEntering = false;
   bool carExiting = false;

   ```
   - IR1 and IR2 define the pins for the IR sensors.
   - totalSlots and availableSlots track the total and available parking slots.
   - carEntering and carExiting are flags to detect car movement.
   
4. Setup Function
   ```cpp
   void setup() {
   Serial.begin(9600);
   lcd.init();
   lcd.backlight();
   pinMode(IR1, INPUT);
   pinMode(IR2, INPUT);
   myservo1.attach(3);
   myservo1.write(100);
   lcd.setCursor(0, 0);
   lcd.print("     ARDUINO    ");
   lcd.setCursor(0, 1);
   lcd.print(" PARKING SYSTEM ");
   delay(2000);
   lcd.clear();
   }
   ```
   - Serial.begin(9600) initializes serial communication at 9600 baud rate.
   - lcd.init() and lcd.backlight() initialize the LCD and turn on its backlight.
   - pinMode(IR1, INPUT) and pinMode(IR2, INPUT) set the IR sensor pins as input.
   - myservo1.attach(3) attaches the servo motor to pin 3 and sets it to the initial position (100).
   - The LCD displays a welcome message for 2 seconds.
   
     
5. Loop Function
   ```cpp
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
   - Car Entering: If IR1 detects a car, the system checks if slots are available. If so, it opens the gate (servo motor), updates the slot count, and displays "Car Entered" on the LCD. If full, it   displays "Parking Full".
   - Car Exiting: If IR2 detects a car exiting, the system opens the gate, updates the slot count, and displays "Car Exited" on the LCD.
   - Reset Flags: The flags carEntering and carExiting are reset once the IR sensors no longer detect the car.
   - Display Status: Continuously displays a welcome message and the number of available slots on the LCD.
   - Debugging Information: Prints the status of the IR sensors and available slots to the serial monitor for debugging
   
     

# Data

The system was tested with a total of 4 parking slots. The following data was recorded during the test:

| Time (min) | IR1 Sensor (Entry) | IR2 Sensor (Exit) | Available Slots | Gate Status |
|------------|---------------------|--------------------|-----------------|-------------|
| 0          | HIGH                | HIGH               | 4               | CLOSED      |
| 2          | LOW                 | HIGH               | 3               | OPEN        |
| 3          | HIGH                | HIGH               | 3               | CLOSED      |
| 6          | HIGH                | LOW                | 4               | OPEN        |
| 7          | HIGH                | HIGH               | 4               | CLOSED      |
| 10         | LOW                 | HIGH               | 3               | OPEN        |
| 11         | HIGH                | HIGH               | 3               | CLOSED      |
| 15         | LOW                 | HIGH               | 2               | OPEN        |
| 16         | HIGH                | HIGH               | 2               | CLOSED      |
| 20         | HIGH                | LOW                | 3               | OPEN        |
| 21         | HIGH                | HIGH               | 3               | CLOSED      |

- **IR1 Sensor (Entry)**: Detects a car entering the parking lot.
- **IR2 Sensor (Exit)**: Detects a car exiting the parking lot.
- **Available Slots**: Tracks the number of parking slots available.
- **Gate Status**: Indicates whether the gate is open or closed based on sensor input and slot availability.
   
# Results

The Automated Car Parking System successfully managed the entry and exit of vehicles, accurately updating the available parking slots on the LCD display. The IR Proximity Sensors reliably detected vehicle presence, and the Arduino-controlled servo motor effectively operated the gate, opening and closing as necessary. The system was able to maintain an accurate count of available parking slots, demonstrating its effectiveness in real-time parking management.

# Conclusion

<div align = "justify">In conclusion, our team at Shahjalal University of Science and Technology, Department of Computer Science & Engineering, has successfully designed and implemented an Automated Car Parking System as part of the "Microprocessor and Interfacing Lab" course (Course Code: CSE-368). Under the guidance of Abdullah Al Noman Sir, we embarked on this project with the goal of leveraging microcontroller technology to enhance parking management systems.

Throughout the project lifecycle, we meticulously integrated components such as Arduino UNO, IR Proximity Sensors, LCD Display, and Servo Motor to automate the detection of parking space availability and control vehicle entry. This system not only demonstrates our proficiency in microprocessor interfacing but also addresses practical challenges in urban parking infrastructure.

We encountered various challenges during the development phase, including hardware integration complexities and software algorithm refinement. Through collaborative effort and innovative problem-solving, we overcame these hurdles and achieved a robust, functional prototype.

Moving forward, we envision expanding this system to accommodate larger parking lots and integrating advanced features such as real-time data analytics and mobile app interfaces for enhanced user experience. This project has equipped us with invaluable skills in embedded systems design, teamwork, and project management, preparing us for future challenges in the field of computer science and engineering.

We extend our sincere gratitude to Abdullah Al Noman Sir for his guidance and support throughout this project, as well as to our fellow team members for their dedication and hard work.
</div>
