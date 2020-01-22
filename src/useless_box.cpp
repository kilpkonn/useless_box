#include <Servo.h>
#include <HardwareSerial.h>
#include <USBAPI.h>

#define LED_PIN 13
#define FRONT_SWITCH_PIN 2
#define HAND_SERVO_PIN 5
#define BOX_SERVO_PIN 6

#define BOX_OPEN_ANGLE 114
#define BOX_CLOSE_ANGLE 85
#define HAND_DOWN_ANGLE 180
#define HAND_UP_ANGLE 35
#define PRESS_BUTTON_ANGLE 23

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
    hand_servo.write(HAND_DOWN_ANGLE);
    box_servo.write(BOX_CLOSE_ANGLE);

    //randomSeed(analogRead(0));
}


void loop() {
    switch_status = digitalRead(FRONT_SWITCH_PIN);
    //action = random(1,16);

    if (switch_status == LOW) {

        if (action == 1) {
            Serial.println("Action 1");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(20);
            }
            for (uint8_t i = HAND_DOWN_ANGLE; i >= HAND_UP_ANGLE; i--) {
                hand_servo.write(i);
                delay(30);
            }
            delay(1000);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(200);
            for (uint8_t i = PRESS_BUTTON_ANGLE; i <= HAND_DOWN_ANGLE; i++) {
                hand_servo.write(i);
                delay(30);
            }
            for (uint8_t i = BOX_OPEN_ANGLE; i >= BOX_CLOSE_ANGLE; i--) {
                box_servo.write(i);
                delay(30);
            }
            action++;
        } else if (action == 2) {
            Serial.println("Action 2");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(15);
            }
            delay(550);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(1100);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1200);
            box_servo.write(BOX_CLOSE_ANGLE);
            delay(1500);
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(15);
            }
            delay(3000);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 3) {
            Serial.println("Action 3");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(15);
            }
            delay(1000);
            box_servo.write(BOX_CLOSE_ANGLE);
            delay(2000);
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(15);
            }
            delay(100);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(1100);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1200);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 4) {
            Serial.println("Action 4");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(30);
            }
            for (uint8_t i = HAND_DOWN_ANGLE; i >= HAND_UP_ANGLE; i--) {
                hand_servo.write(i);
                delay(30);
            }
            delay(2000);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(200);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(400);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 5) {
            Serial.println("Action 5");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(15);
            }
            delay(2000);
            hand_servo.write(HAND_UP_ANGLE + 35);
            delay(550);
            hand_servo.write(HAND_UP_ANGLE + 10);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 35);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 10);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 35);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 10);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 35);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 10);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 35);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 10);
            delay(250);
            hand_servo.write(HAND_UP_ANGLE + 35);
            delay(2000);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(1200);
            hand_servo.write(HAND_UP_ANGLE);
            delay(300);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1300);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 6) {
            Serial.println("Action 6");
            for (uint8_t i = BOX_CLOSE_ANGLE; i < BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(35);
            }
            delay(1000);
            for (uint8_t i = 0; i < 12; i++) {
                for (uint8_t j = BOX_CLOSE_ANGLE; j <= BOX_OPEN_ANGLE; j++) {
                    box_servo.write(j);
                    delay(35);
                }
                delay(250);
            }
            for (uint8_t i = HAND_DOWN_ANGLE; i >= HAND_UP_ANGLE; i--) {
                hand_servo.write(i);
                delay(35);
            }
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(1100);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1000);
            box_servo.write(BOX_CLOSE_ANGLE);
            delay(1500);
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(30);
            }
            delay(3000);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 7) {
            Serial.println("Action 7");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(20);
            }
            delay(400);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(1000);
            for (uint8_t i = 0; i < 4; i++) {
                for (uint8_t j = BOX_CLOSE_ANGLE; j <= BOX_OPEN_ANGLE; j++) {
                    box_servo.write(j);
                    delay(20);
                }
                delay(200);
            }
            delay(500);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(500);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 8) {
            Serial.println("Action 8");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(15);
            }
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(2000);
            for (uint8_t i = 0; i < 7; i++) {
                hand_servo.write(HAND_UP_ANGLE + 40);
                delay(200);
                hand_servo.write(HAND_UP_ANGLE + 5);
                delay(200);
            }
            delay(500);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1000);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 9) {
            Serial.println("Action 9");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE - 15; i++) {
                box_servo.write(i);
                delay(15);
            }
            delay(2000);
            box_servo.write(BOX_OPEN_ANGLE);
            for (uint8_t i = HAND_DOWN_ANGLE; i >= HAND_UP_ANGLE; i--) {
                hand_servo.write(i);
                delay(50);
            }
            delay(500);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(200);
            for (uint8_t i = PRESS_BUTTON_ANGLE; i <= HAND_DOWN_ANGLE; i++) {
                hand_servo.write(i);
                delay(50);
            }
            box_servo.write(BOX_CLOSE_ANGLE);
            delay(2000);
            box_servo.write(BOX_OPEN_ANGLE - 15);
            delay(3000);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 10) {
            Serial.println("Action 10");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE - 15; i++) {
                box_servo.write(i);
                delay(150);
            }
            delay(1000);
            for (uint8_t i = 0; i < 10; i++) {
                for (uint8_t j = BOX_CLOSE_ANGLE; j <= BOX_OPEN_ANGLE - 15; j++) {
                    box_servo.write(j);
                    delay(35);
                }
                delay(150);
            }
            box_servo.write(BOX_OPEN_ANGLE);
            delay(300);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(1200);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1200);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 11) {
            Serial.println("Action 11");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(30);
            }
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(2000);
            for (uint8_t i = 0; i < 3; i++) {
                hand_servo.write(HAND_UP_ANGLE + 35);
                delay(250);
                hand_servo.write(HAND_UP_ANGLE + 5);
                delay(250);
            }
            delay(1500);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(800);
            box_servo.write(BOX_CLOSE_ANGLE);
            delay(1500);
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(20);
            }
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(3000);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(900);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 12) {
            Serial.println("Action 12");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(50);
            }
            delay(1000);
            for (uint8_t i = HAND_DOWN_ANGLE; i >= PRESS_BUTTON_ANGLE; i--) {
                hand_servo.write(i);
                delay(50);
            }
            delay(2000);
            hand_servo.write(HAND_UP_ANGLE);
            delay(1000);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1000);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 13) {
            Serial.println("Action 13");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE; i++) {
                box_servo.write(i);
                delay(25);
            }
            delay(2000);
            for (uint8_t i = HAND_UP_ANGLE; i >= HAND_UP_ANGLE + 30; i--) {
                hand_servo.write(i);
                delay(60);
            }
            for (uint8_t i = 0; i < 3; i++) {
                hand_servo.write(HAND_UP_ANGLE + 30);
                delay(250);
                hand_servo.write(HAND_UP_ANGLE + 5);
                delay(1000);
            }
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(2000);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(500);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 14) {
            Serial.println("Action 14");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE - 20; i++) {
                box_servo.write(i);
                delay(25);
            }
            delay(4000);
            box_servo.write(BOX_OPEN_ANGLE);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(1200);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1200);
            box_servo.write(BOX_OPEN_ANGLE - 10);
            delay(4000);
            box_servo.write(BOX_CLOSE_ANGLE);
            action++;
        } else if (action == 15) {
            Serial.println("Action 15");
            for (uint8_t i = BOX_CLOSE_ANGLE; i <= BOX_OPEN_ANGLE - 10; i++) {
                box_servo.write(i);
                delay(25);
            }
            delay(1000);
            for (uint8_t i = 0; i < 3; i++) {
                for (uint8_t j = BOX_CLOSE_ANGLE; j <= BOX_OPEN_ANGLE - 10; j++) {
                    box_servo.write(j);
                    delay(60);
                }
                for (uint8_t j = BOX_OPEN_ANGLE - 10; j >= BOX_CLOSE_ANGLE; j--) {
                    box_servo.write(j);
                    delay(60);
                }
            }
            for (uint8_t j = BOX_CLOSE_ANGLE; j <= BOX_OPEN_ANGLE; j++) {
                box_servo.write(j);
                delay(60);
            }
            for (uint8_t i = HAND_DOWN_ANGLE; i >= HAND_UP_ANGLE; i--) {
                hand_servo.write(i);
                delay(50);
            }
            delay(1000);
            hand_servo.write(PRESS_BUTTON_ANGLE);
            delay(1100);
            hand_servo.write(HAND_DOWN_ANGLE);
            delay(1100);
            box_servo.write(BOX_CLOSE_ANGLE);
            action = 1;
        }
    }
}
