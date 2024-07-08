#include <Arduino.h>
#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial SerialBT;
int valorRecebido;

#define PINO_SERVO 23
Servo servoCaneta;
int estadoServo = 0;

// Define os pinos de controle do ULN2003A
//E
#define IN1E 32
#define IN2E 33
#define IN3E 25
#define IN4E 26
//D
#define IN1D 27 
#define IN2D 14
#define IN3D 12
#define IN4D 13

// Define a sequência de passos do motor de passos
const int passos[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup() {
  Serial.begin(9600);
  servoCaneta.attach(PINO_SERVO);
  servoCaneta.write(80);
  SerialBT.begin("Impressora 2d");
  Serial.println("O dispositivo já pode ser pareado!");

  pinMode(IN1E, OUTPUT);
  pinMode(IN2E, OUTPUT);
  pinMode(IN3E, OUTPUT);
  pinMode(IN4E, OUTPUT);
  
  pinMode(IN1D, OUTPUT);
  pinMode(IN2D, OUTPUT);
  pinMode(IN3D, OUTPUT);
  pinMode(IN4D, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    valorRecebido = SerialBT.read();

    switch (valorRecebido) {
      case 1:
        Serial.println("Caso 1: valorRecebido é 1"); //caneta
        // Não foi usado
        break;
       case 2:
        Serial.println("Caso 2: valorRecebido é 2"); //caneta
        caneta();
        delay(500); 
        break;
      case 3:
        Serial.println("Caso 3: valorRecebido é 3"); //cima
        motoresPassoSentidoOposto(25, 1);
        delay(2);
        break;
      case 4:
        Serial.println("Caso 4: valorRecebido é 4"); //baixo
        motoresPassoSentidoOposto(25, -1);
        delay(2); 
        break;
      case 5:
        Serial.println("Caso 5: valorRecebido é 5"); //esquerda
        motoresPassoMesmoSentido(25, 1);
        delay(2); 
        break;
      case 6:
        Serial.println("Caso 6: valorRecebido é 6"); //direita
        motoresPassoMesmoSentido(25, -1);
        delay(2); 
        break;
      case 7:
        Serial.println("Caso 7: valorRecebido é 7"); //desenho predefinido 3
        motorPassoE(25, -1); //não usado
        delay(2); 
        break;
      case 8:
        Serial.println("Caso 8: valorRecebido é 8");
        motoresPassoMesmoSentido(25, -1); //não usado
        delay(2); 
        break;
      default:
        Serial.println("Valor padrão: valorRecebido não é 1 nem 2");
        // Faça algo para qualquer outro caso
        break;
    }

    delay(2);  
  }
  
}

// Função para mover o motor de passos E
void motorPassoE(int contagemPassos, int direcao) {
  int indicePasso;
  for (int i = 0; i < contagemPassos; i++) {
    for (int j = 0; j < 8; j++) {
      indicePasso = direcao == 1 ? j : (7 - j);
      digitalWrite(IN1E, passos[indicePasso][0]);
      digitalWrite(IN2E, passos[indicePasso][1]);
      digitalWrite(IN3E, passos[indicePasso][2]);
      digitalWrite(IN4E, passos[indicePasso][3]);
      delay(2);
    }
  }
}

// Função para mover o motor de passos D
void motorPassoD(int contagemPassos, int direcao) {
  int indicePasso;
  for (int i = 0; i < contagemPassos; i++) {
    for (int j = 0; j < 8; j++) {
      indicePasso = direcao == 1 ? j : (7 - j);
      digitalWrite(IN1D, passos[indicePasso][0]);
      digitalWrite(IN2D, passos[indicePasso][1]);
      digitalWrite(IN3D, passos[indicePasso][2]);
      digitalWrite(IN4D, passos[indicePasso][3]);
      delay(2);
    }
  }
}

void motoresPassoMesmoSentido(int contagemPassos, int direcao) {
  int indicePasso;
  for (int i = 0; i < contagemPassos; i++) {
    for (int j = 0; j < 8; j++) {
      indicePasso = direcao == 1 ? j : (7 - j);
      digitalWrite(IN1E, passos[indicePasso][0]);
      digitalWrite(IN2E, passos[indicePasso][1]);
      digitalWrite(IN3E, passos[indicePasso][2]);
      digitalWrite(IN4E, passos[indicePasso][3]);
      digitalWrite(IN1D, passos[indicePasso][0]);
      digitalWrite(IN2D, passos[indicePasso][1]);
      digitalWrite(IN3D, passos[indicePasso][2]);
      digitalWrite(IN4D, passos[indicePasso][3]);
      delay(2);
    }
  }
}

void motoresPassoSentidoOposto(int contagemPassos, int direcao) {
  int indicePassoE, indicePassoD;
  for (int i = 0; i < contagemPassos; i++) {
    for (int j = 0; j < 8; j++) {
      indicePassoE = direcao == 1 ? j : (7 - j);
      indicePassoD = direcao == 1 ? (7 - j) : j;
      digitalWrite(IN1E, passos[indicePassoE][0]);
      digitalWrite(IN2E, passos[indicePassoE][1]);
      digitalWrite(IN3E, passos[indicePassoE][2]);
      digitalWrite(IN4E, passos[indicePassoE][3]);
      digitalWrite(IN1D, passos[indicePassoD][0]);
      digitalWrite(IN2D, passos[indicePassoD][1]);
      digitalWrite(IN3D, passos[indicePassoD][2]);
      digitalWrite(IN4D, passos[indicePassoD][3]);
      delay(2);
    }
  }
}

void caneta() {
  if (estadoServo == 0) {
    servoCaneta.write(170);
    estadoServo = 1;
  } else {
    servoCaneta.write(70);
    estadoServo = 0;
  }
}