#include <Servo.h>
#include <HardwareSerial.h>
#include <USBAPI.h>

#define LED_PIN 13
#define FRONT_SWITCH_PIN 2
#define HAND_SERVO_PIN 5
#define BOX_SERVO_PIN 6

Servo hand_servo;
Servo box_servo;

int switch_status = 0;
uint8_t action = 1;

void setup() {
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);

    hand_servo.attach(HAND_SERVO_PIN);
    box_servo.attach(BOX_SERVO_PIN);
    hand_servo.write(180);
    box_servo.write(70);

    //randomSeed(analogRead(0));
}


void loop() {
    switch_status = digitalRead(FRONT_SWITCH_PIN);
    //action = random(1,16);

    if (switch_status == LOW) {

        if (action == 1) {
            Serial.println("Action 1");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(20);
            }
            for (uint8_t i = 180; i >= 35; i--) {
                hand_servo.write(i);
                delay(20);
            }
            delay(1000);
            hand_servo.write(26);
            delay(200);
            for (uint8_t i = 26; i <= 180; i++) {
                hand_servo.write(i);
                delay(20);
            }
            for (uint8_t i = 110; i >= 70; i--) {
                box_servo.write(i);
                delay(20);
            }
            action++;
        } else if (action == 2) {
            Serial.println("Action 2");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(550);
            hand_servo.write(26);
            delay(550);
            hand_servo.write(180);
            delay(550);
            box_servo.write(70);
            delay(1500);
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(3000);
            box_servo.write(70);
            action++;
        } else if (action == 3) {
            Serial.println("Action 3");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(1000);
            box_servo.write(70);
            delay(2000);
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            hand_servo.write(26);
            delay(550);
            hand_servo.write(180);
            delay(500);
            box_servo.write(70);
            action++;
        } else if (action == 4) {
            Serial.println("Action 4");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(20);
            }
            for (uint8_t i = 180; i >= 35; i--) {
                hand_servo.write(i);
                delay(20);
            }
            delay(2000);
            hand_servo.write(26);
            delay(200);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            action++;
        } else if (action == 5) {
            Serial.println("Action 5");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(2000);
            hand_servo.write(65);
            delay(550);
            hand_servo.write(40);
            delay(200);
            hand_servo.write(65);
            delay(200);
            hand_servo.write(40);
            delay(200);
            hand_servo.write(65);
            delay(200);
            hand_servo.write(40);
            delay(200);
            hand_servo.write(65);
            delay(200);
            hand_servo.write(40);
            delay(200);
            hand_servo.write(65);
            delay(200);
            hand_servo.write(40);
            delay(200);
            hand_servo.write(65);
            delay(2000);
            hand_servo.write(26);
            delay(400);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            action++;
        } else if (action == 6) {
            Serial.println("Action 6");
            for (uint8_t i = 70; i < 110; i++) {
                box_servo.write(i);
                delay(20);
            }
            delay(1000);
            for (uint8_t i = 0; i < 12; i++) {
                for (uint8_t j = 70; j <= 110; j++) {
                    box_servo.write(j);
                    delay(6);
                }
                delay(200);
            }
            for (uint8_t i = 180; i >= 35; i--) {
                hand_servo.write(i);
                delay(30);
            }
            hand_servo.write(26);
            delay(400);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            delay(1500);
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(3000);
            box_servo.write(80);
            action++;
        } else if (action == 7) {
            Serial.println("Action 7");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(400);
            hand_servo.write(26);
            delay(1000);
            for (uint8_t i = 0; i < 6; i++) {
                for (uint8_t j = 70; j <= 110; j++) {
                    box_servo.write(j);
                    delay(6);
                }
                delay(200);
            }
            delay(500);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            action++;
        } else if (action == 8) {
            Serial.println("Action 8");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            hand_servo.write(26);
            delay(2000);
            for (uint8_t i = 0; i < 7; i++) {
                hand_servo.write(75);
                delay(100);
                hand_servo.write(40);
                delay(100);
            }
            delay(500);
            hand_servo.write(180);
            delay(1000);
            box_servo.write(70);
            action++;
        } else if (action == 9) {
            Serial.println("Action 9");
            for (uint8_t i = 70; i <= 105; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(2000);
            box_servo.write(110);
            for (uint8_t i = 180; i >= 35; i--) {
                hand_servo.write(i);
                delay(40);
            }
            delay(500);
            hand_servo.write(26);
            delay(200);
            for (uint8_t i = 26; i <= 180; i++) {
                hand_servo.write(i);
                delay(40);
            }
            box_servo.write(70);
            delay(2000);
            box_servo.write(100);
            delay(3000);
            box_servo.write(70);
            action++;
        } else if (action == 10) {
            Serial.println("Action 10");
            for (uint8_t i = 70; i <= 105; i++) {
                box_servo.write(i);
                delay(100);
            }
            delay(1000);
            for (uint8_t i = 0; i < 10; i++) {
                for (uint8_t j = 70; j <= 100; j++) {
                    box_servo.write(j);
                    delay(6);
                }
                delay(100);
            }
            box_servo.write(110);
            delay(100);
            hand_servo.write(26);
            delay(650);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            action++;
        } else if (action == 11) {
            Serial.println("Action 11");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            hand_servo.write(26);
            delay(2000);
            for (uint8_t i = 0; i < 3; i++) {
                hand_servo.write(65);
                delay(200);
                hand_servo.write(40);
                delay(200);
            }
            delay(1500);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            delay(1500);
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            hand_servo.write(26);
            delay(3000);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            action++;
        } else if (action == 12) {
            Serial.println("Action 12");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(50);
            }
            delay(1000);
            for (uint8_t i = 180; i >= 26; i--) {
                hand_servo.write(i);
                delay(50);
            }
            delay(2000);
            hand_servo.write(26);
            delay(200);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            action++;
        } else if (action == 13) {
            Serial.println("Action 13");
            for (uint8_t i = 70; i <= 110; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(2000);
            for (uint8_t i = 180; i >= 60; i--) {
                hand_servo.write(i);
                delay(40);
            }
            for (uint8_t i = 0; i < 3; i++) {
                hand_servo.write(60);
                delay(200);
                hand_servo.write(40);
                delay(800);
            }
            hand_servo.write(26);
            delay(2000);
            hand_servo.write(180);
            delay(500);
            box_servo.write(70);
            action++;
        } else if (action == 14) {
            Serial.println("Action 14");
            for (uint8_t i = 70; i <= 105; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(4000);
            box_servo.write(110);
            hand_servo.write(26);
            delay(650);
            hand_servo.write(180);
            delay(500);
            box_servo.write(100);
            delay(4000);
            box_servo.write(70);
            action++;
        } else if (action == 15) {
            Serial.println("Action 15");
            for (uint8_t i = 70; i <= 105; i++) {
                box_servo.write(i);
                delay(6);
            }
            delay(1000);
            for (uint8_t i = 0; i < 3; i++) {
                for (uint8_t j = 70; j <= 105; j++) {
                    box_servo.write(j);
                    delay(50);
                }
                for (uint8_t j = 105; j >= 70; j--) {
                    box_servo.write(j);
                    delay(50);
                }
            }
            for (uint8_t j = 70; j <= 110; j++) {
                box_servo.write(j);
                delay(50);
            }
            for (uint8_t i = 180; i >= 35; i--) {
                hand_servo.write(i);
                delay(40);
            }
            delay(1000);
            hand_servo.write(26);
            delay(400);
            hand_servo.write(180);
            delay(400);
            box_servo.write(70);
            action = 1;
        }
    }
}
