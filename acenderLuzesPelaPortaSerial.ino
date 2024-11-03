int vermelho = 7;
int amarelo = 6;
int azul = 5;
int verde = 4;

int leds[] = {vermelho,amarelo,azul,verde};

void setup() {

  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

    if (Serial.available() > 0) {


    // Lê o valor inteiro da porta serial
    int valorRecebido = Serial.parseInt();

      if(valorRecebido == 100){
          reiniciar();
      }

      digitalWrite(valorRecebido, HIGH);

      // Imprime os elementos da matriz
      for(int i = 0; i < 4; i++) {
         if(leds[i] != valorRecebido){
            digitalWrite(leds[i], LOW);
         }
      }

      Serial.println("LED ligado");
  
    }
}

void reiniciar(){
      for(int i = 0; i < 4; i++) {
        digitalWrite(leds[i], LOW);
      }
}
