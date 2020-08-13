/*
 * Firmware for Arduino Mega 2560
 *
 * Thanks github.com/LoSk-p for the base source code and assembling
 */

const uint8_t EN1    = 6;       // pin for L_EN and R_EN drivers pins right side
const uint8_t L_PWM1 = 8;       // L_PWM drivers pin right side
const uint8_t R_PWM1 = 7;       // R_PWM dirvers pin right side
const uint8_t EN2    = 10;      // accordingly left side
const uint8_t L_PWM2 = 11;
const uint8_t R_PWM2 = 12;
const float rad = 0.06;          // Wheel radius, m
int val;
int LED = 13;
int times = 0;
int times_prev = 0;
int del;
float num_rev;      // count wheel rotations
float d = 0;


void move_forvard() {                              //2
    delay(40);
    digitalWrite(L_PWM1, LOW );
    digitalWrite(R_PWM1, HIGH);
    analogWrite (EN1,    140 );
    delay(40);
    digitalWrite(L_PWM2, LOW );
    digitalWrite(R_PWM2, HIGH);
    analogWrite (EN2,    140 );
}

void move_back() {                                 //4
    delay(40);
    digitalWrite(L_PWM1, HIGH);
    digitalWrite(R_PWM1, LOW );
    digitalWrite(EN1,    140 );
    delay(40);
    digitalWrite(L_PWM2, HIGH);
    digitalWrite(R_PWM2, LOW );
    digitalWrite(EN2,    140 );
}

void stop_move() {                                 //5
    delay(40);
    digitalWrite(L_PWM1, HIGH);
    digitalWrite(R_PWM1, HIGH);
    analogWrite (EN1,    140 );
    delay(40);
    digitalWrite(L_PWM2, HIGH);
    digitalWrite(R_PWM2, HIGH);
    analogWrite (EN2,    140 );
}

void turn_right() {                                 //3
    delay(40);
    digitalWrite(L_PWM2, LOW );    // Right side forward
    digitalWrite(R_PWM2, HIGH);
    analogWrite (EN2,    140 );
    delay(40);
    digitalWrite(L_PWM1, HIGH);    // Left side backwards
    digitalWrite(R_PWM1, LOW );
    analogWrite (EN1,    140 );
}

void turn_left() {                                   //1
    delay(40);
    digitalWrite(L_PWM1, LOW );    //Левые колеса вперед
    digitalWrite(R_PWM1, HIGH);
    analogWrite (EN1,    140 );
    delay(40);
    digitalWrite(L_PWM2, HIGH);    //Правые колеса назад
    digitalWrite(R_PWM2, LOW );
    analogWrite (EN2,    140 );

}

float dist() {  // distance from odometry
  int Htime;    // High pulse duration
  int Ltime;    // Low pulse duration
  float obs;    // rotations per second
  float fr;     // frequency
  float obor = 0;    // Rotations
  Htime = pulseIn(3,HIGH);
  Ltime = pulseIn(3,LOW);
  if (Htime != 0 && Ltime != 0) {
    fr = 100000/(Htime + Ltime);
  }else {
    fr = 0;
  }
  obs = fr/24;
  times_prev = times;
  times = millis();
  del = times - times_prev;
  obor = obor + obs*del/1000;
  return obor;
}

void setup() {
  Serial3.begin(9600);
  //Serial.begin(9600);
  pinMode(3,   INPUT);
  pinMode(LED, OUTPUT);
  pinMode(EN1,    OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  pinMode(R_PWM1, OUTPUT);
  pinMode(EN2,    OUTPUT);
  pinMode(L_PWM2, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
}

void loop() {
  float distanse;
  int dis;
  if (Serial3.available())  {
    val = Serial3.read();
    switch (val) {
      case '1':
        Serial3.println("Turning left");
        turn_left();
        break;
      case '2':
      Serial3.println("Moving forward");
        move_forvard();
        break;
      case '3':
      Serial3.println("Turning right");
        turn_right();
        break;
      case '4':
      Serial3.println("Moving back");
        move_back();
        break;
      case '5':
      Serial3.println("Stop");
        stop_move();
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        break;
      case '6':
        d = 0;
        move_forvard();
        while (d < 2) {
          delay(40);
          d = d + 2*PI*rad*dist();
          //Serial3.println(d);
        }
        stop_move();
        Serial3.println("Done");
        delay(40);
        break;
      case 'w':              // forward for N meters
        d = 0;
        while (!Serial3.available());
        distanse = Serial3.read() - '0';
        Serial3.print("Moving forward ");
        Serial3.print(distanse);
        Serial3.println(" m");
        //dis = distanse.toInt();
        //Serial3.println(dis);
        move_forvard();
        while (d < distanse) {
          delay(40);
          d = d + 2*PI*rad*dist();
          //Serial3.println(d);
        }
        stop_move();
        Serial3.println("Done");
        delay(40);
        break;
      case 'a':                 // Turn left 2 - 45degrees; 4-90d; 8-180d
        d = 0;
        while (!Serial3.available());
        distanse = Serial3.read() - '0';
        Serial3.print("Turning left ");
        Serial3.println(distanse*22.5);
        //dis = distanse.toInt();
        //Serial3.println(dis);
        turn_left();
        while (d*5.714 < distanse) {
          delay(40);
          d = d + 2*PI*rad*dist();
          //Serial3.println(d);
        }
        stop_move();
        Serial3.println("Done");
        delay(40);
        break;
      case 'd':                 // Turn right 2 - 45; 4-90; 8 - 180
        d = 0;
        while (!Serial3.available());
        distanse = Serial3.read() - '0';
        Serial3.print("Turning right ");
        Serial3.println(distanse*22.5);
        //dis = distanse.toInt();
        //Serial3.println(dis);
        turn_right();
        while (d*5.714 < distanse) {
          delay(40);
          d = d + 2*PI*rad*dist();
          //Serial3.println(d);
        }
        stop_move();
        Serial3.println("Done");
        delay(40);
        break;
      case 's':              // Backwards for N meters
        d = 0;
        while (!Serial3.available());
        distanse = Serial3.read() - '0';
        Serial3.print("Moving back ");
        Serial3.print(distanse);
        Serial3.println(" m");
        //dis = distanse.toInt();
        //Serial3.println(dis);
        move_back();
        while (d < distanse) {
          delay(40);
          d = d + 2*PI*rad*dist();
        }
        stop_move();
        Serial3.println("Done");
        delay(40);
        break;
    }
  }
  delay(40);
  num_rev = num_rev + dist();
  //EEPROM.put(0, num_rev);
  delay(40);
}

