#include <Arduino.h>
#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial SerialBT;
int valorRecebido;

#define SERVO_PIN 22
Servo myServo;
int servoState = 0;

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
const int steps[8][4] = {
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
  Serial.begin(115200);
  myServo.attach(SERVO_PIN);
  myServo.write(0);
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

/*
Case 1 reinicia a posição da caneta
case 2 Ativa ou desativa a caneta
case 3 sobe a posição da caneta
case 4 abaixa a posição da caneta
case 5 move a caneta para a esquerda
case 6 move a caneta para a direita
case 7 Desenho pre programado "creeper"
case 8 Desenho pre programado "Cubo"
*/

void loop() {
  if (SerialBT.available()) {
    valorRecebido = SerialBT.read();

    switch (valorRecebido) {
      case 1:
        Serial.println("Caso 1: valorRecebido é 1");
        // Faça algo para o caso 1
        break;
      case 2:
        Serial.println("Caso 2: valorRecebido é 2");
        caneta();
        break;
      case 3:
        Serial.println("Caso 3: valorRecebido é 3");
        stepperMotorsentidooposto(200, 1);
        delay(2);
        break;
      case 4:
        Serial.println("Caso 4: valorRecebido é 4");
        stepperMotorsentidooposto(200, -1);
        delay(2); 
        break;
      case 5:
        Serial.println("Caso 5: valorRecebido é 5");
        stepperMotorE(100, 1);
        delay(2); 
        break;
      case 6:
        Serial.println("Caso 6: valorRecebido é 6");
        stepperMotorD(100, 1);
        delay(2); 
        break;
      case 7:
        Serial.println("Caso 7: valorRecebido é 7");
        stepperMotorE(100, -1);
        delay(2); 
        break;
      case 8:
        Serial.println("Caso 8: valorRecebido é 8");
        stepperMotormesmosentido(100,1);
        delay(2); 
        break;
      default:
        Serial.println("Valor padrão: valorRecebido não é 1 nem 2");
        // Faça algo para qualquer outro caso
        break;
    }

    delay(1000);  // Aguarda 1 segundo antes de repetir o loop
  }
}

// Função para mover o motor de passos E
void stepperMotorE(int stepsCount, int direction) {
  int stepIndex;
  for (int i = 0; i < stepsCount; i++) {
    for (int j = 0; j < 8; j++) {
      stepIndex = direction == 1 ? j : (7 - j);
      digitalWrite(IN1E, steps[stepIndex][0]);
      digitalWrite(IN2E, steps[stepIndex][1]);
      digitalWrite(IN3E, steps[stepIndex][2]);
      digitalWrite(IN4E, steps[stepIndex][3]);
      delay(2);
    }
  }
}

// Função para mover o motor de passos D
void stepperMotorD(int stepsCount, int direction) {
  int stepIndex;
  for (int i = 0; i < stepsCount; i++) {
    for (int j = 0; j < 8; j++) {
      stepIndex = direction == 1 ? j : (7 - j);
      digitalWrite(IN1D, steps[stepIndex][0]);
      digitalWrite(IN2D, steps[stepIndex][1]);
      digitalWrite(IN3D, steps[stepIndex][2]);
      digitalWrite(IN4D, steps[stepIndex][3]);
      delay(2);
    }
  }
}

void stepperMotormesmosentido(int stepsCount, int direction) {
  int stepIndex;
  for (int i = 0; i < stepsCount; i++) {
    for (int j = 0; j < 8; j++) {
      stepIndex = direction == 1 ? j : (7 - j);
      digitalWrite(IN1E, steps[stepIndex][0]);
      digitalWrite(IN2E, steps[stepIndex][1]);
      digitalWrite(IN3E, steps[stepIndex][2]);
      digitalWrite(IN4E, steps[stepIndex][3]);
      digitalWrite(IN1D, steps[stepIndex][0]);
      digitalWrite(IN2D, steps[stepIndex][1]);
      digitalWrite(IN3D, steps[stepIndex][2]);
      digitalWrite(IN4D, steps[stepIndex][3]);
      delay(2);
    }
  }
}

void stepperMotorsentidooposto(int stepsCount, int direction) {
  int stepIndexE, stepIndexD;
  for (int i = 0; i < stepsCount; i++) {
    for (int j = 0; j < 8; j++) {
      stepIndexE = direction == 1 ? j : (7 - j);
      stepIndexD = direction == 1 ? (7 - j) : j;
      digitalWrite(IN1E, steps[stepIndexE][0]);
      digitalWrite(IN2E, steps[stepIndexE][1]);
      digitalWrite(IN3E, steps[stepIndexE][2]);
      digitalWrite(IN4E, steps[stepIndexE][3]);
      digitalWrite(IN1D, steps[stepIndexD][0]);
      digitalWrite(IN2D, steps[stepIndexD][1]);
      digitalWrite(IN3D, steps[stepIndexD][2]);
      digitalWrite(IN4D, steps[stepIndexD][3]);
      delay(2);
    }
  }
}

void caneta() {
  if (servoState == 0) {
    myServo.write(155);
    servoState = 1;
  } else {
    myServo.write(0);
    servoState = 0;
  }
}