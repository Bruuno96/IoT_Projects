#include <Ultrasonic.h>
#include <Servo.h>

HC_SR04 sensor1(3, 2); // (trigger, echo)
int distancia;
int state;
Servo servo_motor;

void setup() {
  Serial.begin(9600);
  servo_motor.attach(9);
}

void loop() {
//  Serial.println(String("Distância: ") + sensor1.distance() + String(" cm"));
  if (Serial.available() > 0) {
    state = Serial.parseInt();
    Serial.println(state);
  }

  distancia = sensor1.distance();

  if (state == 1) {
    if (distancia < 20) {
      Serial.println("Tem cafe");
      servo_motor.write(90);
    } else {
      Serial.println("Nao tem cafe");
      servo_motor.write(0);
    }
    delay(100);
  }

  if (state == 2) {
    servo_motor.write(90);
    if (distancia > 30) {
      Serial.println("Cafe longo");
      servo_motor.write(0);
      delay(6000);
    } else {
      Serial.println("Cafe curto");
      servo_motor.write(180);
      delay(3000);
    }

    delay(100);
  }

}
