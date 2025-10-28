const int vermelho = 12;
const int verde = 13;
const int amarelo = 11;

unsigned long tempoAnterior = 0;
int estado = 0;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
}

void loop() {
  unsigned long agora = millis();

  if (estado == 0) {
    digitalWrite(vermelho, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    tempoAnterior = agora;
    estado = 1;
  }

  if (estado == 1 && agora - tempoAnterior >= 6000) {
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);
    tempoAnterior = agora;
    estado = 2;
  }

  if (estado == 2 && agora - tempoAnterior >= 4000) {
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);
    tempoAnterior = agora;
    estado = 3;
  }

  if (estado == 3 && agora - tempoAnterior >= 2000) {
    digitalWrite(amarelo, LOW);
    estado = 0; // reinicia o ciclo
  }
}