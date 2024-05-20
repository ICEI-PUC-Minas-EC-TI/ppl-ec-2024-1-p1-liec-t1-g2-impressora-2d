#include <Arduino.h>
#include <BluetoothSerial.h>
#include <Servo.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
int valorRecebido;

const int led = 2;
int pos = 0;
Servo servo_9;

void setup() {
 Serial.begin(9600);
 servo_9.attach(9, 500, 2500);
 SerialBT.begin("Impressora 2d");
 Serial.println("O dispositivo já pode ser pareado!");
 pinMode(led, OUTPUT);
}
/*
Case 1 reinicia a posição da caneta
case 2 Ativa ou desativa a caneta
caso 3 suba a posição da caneta
case 4 abaixa a posição da caneta
caso 5 mova a caneta para a esquerda
caso 6 mova a caneca para a direita
case 7 Desenho pre programado "creper"
case 8 Desenho pre programado "Cubo"
*/
void loop(){
 valorRecebido =(int)SerialBT.read();

  switch (valorRecebido) {
    case 1:
      Serial.println("Caso 1: valorRecebido é 1");
      // Faça algo para o caso 1
      break;
    case 2:
      Serial.println("Caso 2: valorRecebido é 2");
      // Faça algo para o caso 2
      break;
    case 3:
      Serial.println("Caso 3: valorRecebido é 3");
      // Faça algo para o caso 3
      break;
    case 4:
      Serial.println("Caso 4: valorRecebido é 4");
      // Faça algo para o caso 4
      break;
    case 5:
      Serial.println("Caso 5: valorRecebido é 5");
      // Faça algo para o caso 5
      break;
    case 6:
      Serial.println("Caso 6: valorRecebido é 6");
      // Faça algo para o caso 6
      break;
    case 7:
      Serial.println("Caso 7: valorRecebido é 7");
      // Faça algo para o caso 7
      break;
    case 8:
      Serial.println("Caso 8: valorRecebido é 8");
      // Faça algo para o caso 8
      break;
    default:
      Serial.println("Valor padrão: valorRecebido não é 1 nem 2");
      // Faça algo para qualquer outro caso
  }

  delay(1000);  // Aguarda 1 segundo antes de repetir o loop
}
