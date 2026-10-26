
#include <LiquidCrystal_I2C.h>

// Ultrasonic sensor pins
const int trigPin = 3;
const int echoPin = 2;

// LED and buzzer pins
const int greenLED = 4;
const int yellowLED = 5;
const int redLED = 6;
const int buzzer = 7;

// LCD: I2C address, columns, rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Distance Monitor");

  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  delay(1500);
  lcd.clear();
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo duration
  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    // No valid echo received
    Serial.println("No echo detected");

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    noTone(buzzer);

    lcd.setCursor(0, 0);
    lcd.print("Distance: -- cm ");

    lcd.setCursor(0, 1);
    lcd.print("No echo detected");
  }
  else {
    // Convert echo duration to distance in cm
    float distance = duration / 58.0;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Display measured distance
    lcd.setCursor(0, 0);
    lcd.print("Distance:       ");
    lcd.setCursor(10, 0);
    lcd.print(distance, 1);
    lcd.print("cm");

    if (distance > 30) {
      // SAFE ZONE
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
      noTone(buzzer);

      lcd.setCursor(0, 1);
      lcd.print("Status: SAFE    ");
    }
    else if (distance > 10) {
      // WARNING ZONE
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
      tone(buzzer, 1000, 100);

      lcd.setCursor(0, 1);
      lcd.print("Status: WARNING ");
    }
    else {
      // DANGER ZONE
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);
      tone(buzzer, 1000);

      lcd.setCursor(0, 1);
      lcd.print("Status: DANGER  ");
    }
  }

  delay(200);
}
