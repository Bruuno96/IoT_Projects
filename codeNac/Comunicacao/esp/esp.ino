char dado;
int num;
bool statusDado = true;

void setup() {
  Serial.begin(115200);
}


void loop() {

  if (Serial.available() > 0) {
    if (statusDado) {
      dado = Serial.read();
      Serial.print("Pot: ");Serial.print(dado);
      statusDado = false;
    }
    num = Serial.parseInt();
    Serial.print(" Valor: ");Serial.println(num);
  } else {
    statusDado = true;
  }
}
