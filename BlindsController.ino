#include <RTC.h>

const int pwmPin = 3;        
const int directionPin = 12; // Direction control (IN1)
const int directionPin2 = 11; // Direction control (IN2)

bool directionState = true;
bool triggeredToday = false;

void setup() {
    Serial.begin(9600);
    while(!Serial);
    RTC.begin();

    pinMode(directionPin, OUTPUT);
    pinMode(directionPin2, OUTPUT);
    pinMode(pwmPin, OUTPUT);

    // Ensure motor is off at startup
    digitalWrite(directionPin, LOW);
    digitalWrite(directionPin2, LOW);
    analogWrite(pwmPin, 0);
}

void loop() {
    auto currentTime = RTC.getTime();

    int hour = currentTime.hour;
    int minute = currentTime.minute;
    int second = currentTime.second;

    Serial.printf("Time: %02d:%02d:%02d\n", hour, minute, second);

    // Trigger at 8:00:00
    if (hour == 8 && minute == 0 && second == 0 && !triggeredToday)
    {
        Serial.println('Motor Triggered');
        runMotor(directionState);
        directionState = !directionState;
    }

    if(hour == 8 && minute == 1)
    {
        triggeredToday = false;
    }
    delay(1000);
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
