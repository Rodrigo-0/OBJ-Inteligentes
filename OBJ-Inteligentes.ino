// Biblioteca do Blynk (controle remoto do rele)
#define BLYNK_PRINT DebugSerial
// Parametros para auxiliar o blynk a funcionar normalmente
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX
#include <BlynkSimpleStream.h>
char auth[] = "ABX2VT3uAuqcYxGYMLmjNS-sgaYWjGVY";

//definições do hardware
#define    rele    13       //sinal de saída para o módulo relé
#define    sens     8       //entrada para leitura do sensor

//Cria duas variaveis para realizar a leitura do Sensor
bool leituraSensor;
bool leituraAnterior;

void setup() {
  // Debug console
  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);

  //Definição das portas para identificação no Arduino
  //Sensor
  pinMode(sens, INPUT);

  //Atuador
  pinMode(rele, OUTPUT);
  
}

void loop() {
  //Funcionamento em rotina
  
  leituraSensor = digitalRead(sens); //Variavel que guarda a informação vinda do sensor
  
  //Quando o sensor identificar o solo seco, realiza-se a comparação no if
  if (leituraSensor && !leituraAnterior) {
     while (digitalRead(sens)) { //condição que liga o rele/solenoide em caso de solo seco
        digitalWrite(rele, HIGH);   // Liga o rele, que posteriormente liga a solenoide
        delay(60000);
        digitalWrite(rele, LOW);   //  Desliga o rele, que posteriormente desliga a solenoide

        delay(10000);
     }
  }
  leituraAnterior = leituraSensor;
}
