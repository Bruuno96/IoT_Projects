#define btn1 12
#define btn2 6
#define pot1 A0
#define btn1pot2 5
#define btn2pot2 7

int buttonStatus1;
int buttonStatus2;

int button1Pot2Status;
int button2pot2Status;

int leituraPot1 = 0;
int leituraPot2 = 0;

void setup() {
  pinMode(pot1, INPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn1pot2, INPUT_PULLUP);
  pinMode(btn2pot2, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

  if (canInterrupt()) {
    buttonStatus1 = digitalRead(btn1);
    buttonStatus2 = digitalRead(btn2);

    button1Pot2Status = digitalRead(btn1pot2);
    button2pot2Status = digitalRead(btn2pot2);

    if ((buttonStatus1 == LOW)) {
      leituraPot1 = analogRead(pot1);
      Serial.print("A");Serial.println(leituraPot1);
      delay(500);
    }
    if ((buttonStatus2 == LOW)) {
      leituraPot1 = analogRead(pot1);
      Serial.print("B");Serial.println(leituraPot2);
      delay(500);
    }
    if ((button1Pot2Status == LOW)) {
      leituraPot2 = leituraPot2 + 10;
      delay(100);
    }
    if ((button2pot2Status == LOW)) {
      if(leituraPot2 > 0){
        leituraPot2 = leituraPot2 - 10;
      }
      delay(100);
    }
  }
}

bool canInterrupt()
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();

  // Verifica se a ultima interrupção foi à 200 ms
  if (interrupt_time - last_interrupt_time > 200)
  {
    last_interrupt_time = interrupt_time;
    return true;
  }
  return false;
}
