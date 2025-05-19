//A2 Team code

#include <LiquidCrystal.h>
#include <Servo.h>

// LCD pins: RS=13, E=A1, D4=A2, D5=A3, D6=A4, D7=A5
LiquidCrystal lcd(13, A1, A2, A3, A4, A5);
Servo     batteryServo;

// Pins
const int cardBtn         = 2;
const int batteryBtn      = 3;
const int smallBtn        = 8;
const int mediumBtn       = 11;
const int largeBtn        = 12;
const int motorPin        = 9;
const int batteryServoPin = 10;

// Servo angles
const int neutralAngle = 90;
// const int pushAngle    = 180;
// const int pushAngle    = neutralAngle - 30; // left
const int pushAngle    = neutralAngle + 60;  // right

bool sessionActive = false;

// Prompt welcome screen to LCD
void showWelcome() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tap card to");
  lcd.setCursor(0,1);
  lcd.print("begin (Start)");
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  delay(50);
  showWelcome();

  pinMode(cardBtn,    INPUT_PULLUP);
  pinMode(batteryBtn, INPUT_PULLUP);
  pinMode(smallBtn,   INPUT_PULLUP);
  pinMode(mediumBtn,  INPUT_PULLUP);
  pinMode(largeBtn,   INPUT_PULLUP);

  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);

  batteryServo.attach(batteryServoPin);
  batteryServo.write(neutralAngle);
}

void loop() {
  // Card swipe
  if (!sessionActive && digitalRead(cardBtn)==LOW) {
    sessionActive = true;
    lcd.clear(); 
    lcd.print("Card scanned");
    lcd.setCursor(0,1); 
    lcd.print("Select size:");
    delay(200);
  }

  // Size select
  if (sessionActive) {
    if (digitalRead(smallBtn)==LOW) {
      runSmallFlow();
      sessionActive = false;
      showWelcome();
    }
    else if (digitalRead(mediumBtn)==LOW) {
      lcd.clear(); 
      lcd.print("Medium item");
      lcd.setCursor(0,1); 
      lcd.print("selected");
      delay(1500);

      lcd.clear(); lcd.print("Locker door");
      lcd.setCursor(0,1); lcd.print("Open");
      delay(2000);

      lcd.clear(); lcd.print("Locker door");
      lcd.setCursor(0,1); lcd.print("Closed");
      delay(1500);

      lcd.clear(); lcd.print("Thank You UoM!");
      lcd.setCursor(0,1); lcd.print("UoM *5 Points*");
      delay(2000);

      sessionActive = false;
      showWelcome();
    }
    else if (digitalRead(largeBtn)==LOW) {
      lcd.clear(); 
      lcd.print("Large item");
      lcd.setCursor(0,1); 
      lcd.print("selected");
      delay(1500);

      lcd.clear(); lcd.print("Service Now");
      lcd.setCursor(0,1); lcd.print("Making Request..");
      delay(1500);

      lcd.clear(); lcd.print("Service Now");
      lcd.setCursor(0,1); lcd.print("Receipt #2345");
      delay(1500);

      lcd.clear(); lcd.print("Thank You UoM!");
      lcd.setCursor(0,1); lcd.print("UoM *10 Points*");
      delay(2000);

      sessionActive = false;
      showWelcome();
    }
  }
}

void runSmallFlow() {
  // prompt & wait for Start / Swipe Card
  lcd.clear();
  lcd.print("Ready! Place");
  lcd.setCursor(0,1);
  lcd.print("item inside");
  delay(2000);

  lcd.clear();
  lcd.print("Press Start");
  lcd.setCursor(0,1);
  lcd.print("When ready..");
  // wait for another card tap (start) on pin 2 to begin battery countdown
  while (digitalRead(cardBtn) == HIGH) {
    /* wait */
  }
  delay(200);  // debounce


  // Battery countdown
  bool isBatt = false;
  for (int sec = 10; sec > 0; sec--) {
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("Battery?");
    lcd.setCursor(0,1);
    lcd.print("Press in ");
    lcd.print(sec);
    lcd.print("s");
    unsigned long t0 = millis();
    while (millis() - t0 < 1000) {
      if (digitalRead(batteryBtn) == LOW) {
        isBatt = true;
        break;
      }
    }
    if (isBatt) break;
  }

  // Show result
  lcd.clear();
  lcd.print(isBatt ? "Battery OK" : "No Battery");
  delay(500);

  // If battery, hold servo in push pos during the sort
  if (isBatt) {
    batteryServo.write(pushAngle);
    lcd.print("Battery E-Waste");
    delay(500);
  }

  // Conveyor run 5s
  lcd.clear(); lcd.print("Sorting...");
  digitalWrite(motorPin, HIGH);
  delay(5000);
  digitalWrite(motorPin, LOW);

  // Return servo moved
  if (isBatt) {
    batteryServo.write(neutralAngle);
    delay(500);
  }

  // Completed
  lcd.clear(); lcd.print("Thank You UoM!");
  lcd.setCursor(0,1); lcd.print("UoM *2 Points*");
  delay(2000);
}