// Biblioteca do Blynk (controle remoto do rele)
#define BLYNK_PRINT DebugSerial

//definições do hardware
#define    rele    13       //sinal de saída para o módulo relé
#define    sens     8       //entrada para leitura do sensor

// Parametros para auxiliar o blynk a funcionar normalmente
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX
#include <BlynkSimpleStream.h>
char auth[] = "ABX2VT3uAuqcYxGYMLmjNS-sgaYWjGVY";

// Codigo para todo o funcionamento
void setup()
{
  // Debug console
  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);


  pinMode(rele, OUTPUT);   // configura saída: sinal do relé
  pinMode(sens,  INPUT);   // configura entrada: sensor

  digitalWrite(rele, LOW); // estado inicial do rele
} // fim do system startup

void loop()
{
  Blynk.run();
  pinMode(rele, OUTPUT);   // configura saída: sinal do relé
  pinMode(sens,  INPUT);   // configura entrada: sensor

  digitalWrite(rele, LOW); //rele inicia desligado
} //fim do loop
