const int pwmPin = 3;        
const int directionPin = 12; // Direction control (IN1)
const int directionPin2 = 11; // Direction control (IN2)

bool directionState = true;
// replace code below to set to 12 hour interval for blinds control
const unsigned long interval = 10000; // 12UL * 60 * 60 * 1000; 
unsigned long previousMillis = 0;

void setup() {
    pinMode(directionPin, OUTPUT);
    pinMode(directionPin2, OUTPUT);
    pinMode(pwmPin, OUTPUT);

    // Ensure motor is off at startup
    digitalWrite(directionPin, LOW);
    digitalWrite(directionPin2, LOW);
    analogWrite(pwmPin, 0);
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        runMotor(directionState);
        directionState = !directionState;
    }
}

void runMotor(bool direction) {
    if (direction) {
        digitalWrite(directionPin, HIGH);
        digitalWrite(directionPin2, LOW);
    } else {
        digitalWrite(directionPin, LOW);
        digitalWrite(directionPin2, HIGH);
    }
    
    analogWrite(pwmPin, 30);  
    delay(5000);              

    digitalWrite(directionPin, HIGH);
    digitalWrite(directionPin2, HIGH);

    analogWrite(pwmPin, 0);   
}
