int stateGame = 0;
int nivel = 1;
#define led1 8
#define led2 9
#define led3 10
String led[] = {"led1", "led2", "led3"};
String sequenciaNumerica = "";
String recebido;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  switch (stateGame){
    case 0:
        // inicio de jogo
      Serial.println("* INICIO *");
      Serial.println("Comecar? (s/n)");
      leserial();
      if (recebido.equalsIgnoreCase("s")){
        stateGame = 1;
        Serial.println("Jogo começando...");
        piscaled(1000,3);
      } else {
        stateGame = 2;
        Serial.println("Jogo não iniciado"); 
        piscaled(300,5);     
      }
      break;
    case 2:
      // Game over!!!
      Serial.println("Game Over"); 
      piscaled(100,5);
      stateGame = 3;
      break;
    case 3:
      Serial.println("jogar novamente? (s/n)"); 
      leserial();
      if (recebido.equalsIgnoreCase("s")){
        stateGame = 0;
        Serial.println("Jogo comecando...");
        piscaled(1000,3);
      } else {
        stateGame = 2;
        Serial.println("Jogo nao iniciado"); 
        piscaled(300,5);     
      }
    case 1:
      // Nivel 1 
      Serial.print("* Nivel ");Serial.print(nivel);Serial.println(" *");
      geraSequencia(1000-30*nivel, nivel); 
      leserial();
      if (recebido == sequenciaNumerica){
        stateGame = 1;
        Serial.println("Parabens! proximo nivel.");
        piscaled(1000,3);
        nivel++;
      } else {
        stateGame = 3;
        nivel = 1;
        Serial.println("Errooooo!!!"); 
        piscaled(300,5);  
      }
      break;
}
}

void piscaled(int tempo, int vezes){
  for(int i = 0;i < vezes; i++){

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(tempo);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(tempo);
  }
}

void leserial(){

  Serial.println("* Insera sua resposta *");

  // Aguardar a resposta do usuario
  while (Serial.available() == 0)
  {}

  // Guardar o valor introduzido pelo utilizador no Serial Monitor numa String user
  if (Serial.available())
  {
    recebido = Serial.readString();
  }
}

void geraSequencia (int tempo, int sequencia){
  sequenciaNumerica = "";

  // Pisca os LEDs na sequencia gerada
  for (int j = 0; j < sequencia; j++){
    int numeroGerado = random(0, 3);
    String ledVerifica = led[numeroGerado];
    int ledSoma = 0;
    if (ledVerifica == "led1"){
      digitalWrite(led1, HIGH);
      delay(tempo);
      digitalWrite(led1, LOW);
      delay(tempo);
      ledSoma = 1;
    }else if (ledVerifica == "led2"){
      digitalWrite(led2, HIGH);
      delay(tempo);
      digitalWrite(led2, LOW);
      delay(tempo);
      ledSoma = 2;
    }else if (ledVerifica == "led3"){
      digitalWrite(led3, HIGH);
      delay(tempo);
      digitalWrite(led3, LOW);
      delay(tempo);
      ledSoma = 3;
    }
    // Converte a lista numa String   
    sequenciaNumerica = sequenciaNumerica + ledSoma;
  }
}
