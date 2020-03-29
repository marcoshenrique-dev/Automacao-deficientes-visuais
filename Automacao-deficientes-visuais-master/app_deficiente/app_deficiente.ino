/* Automação para deficientes visuais

   criado por Marcos Henrique

   criado e modificado:
   28/04/2019 ás 9:28 da manhã

   -----------------------------------------------------------------

   Redes de comunicação

   https://www.linkedin.com/in/marcos-henrique-1692681a0/
   https://github.com/robotica-desafios
   https://medium.com/@marcoshenriqueh393
   https://www.youtube.com/channel/UC3ZaLCltfI-34EQaZmWFaeg?view_as=subscriber
   Email : marcoshenriqueh393@gmail.com

*/

#include <SoftwareSerial.h>
SoftwareSerial bluetooth (A1, A0);

//cômodos
#define banheiro 3
#define cozinha 4
#define quarto2 5
#define quarto1 6
#define quintal 7
#define luzGaragem 8
#define luzCentral 9
#define luzVerde 10
#define ventilador 11
#define luzExterna 12

//Declaração de variaveis

char z;

void setup() {

  bluetooth.begin (9600);

  pinMode(luzGaragem, OUTPUT);
  pinMode(luzCentral, OUTPUT);
  pinMode(luzVerde, OUTPUT);
  pinMode(ventilador, OUTPUT);
  pinMode(luzExterna, OUTPUT);
  pinMode(quintal, OUTPUT);
  pinMode(banheiro, OUTPUT);
  pinMode(quarto1, OUTPUT);
  pinMode(quarto2, OUTPUT);
  pinMode(cozinha, OUTPUT);
  Serial.begin(9600);
  
  //Deixando os reles em LOW
  digitalWrite(cozinha, !HIGH);
  digitalWrite(quarto1, !HIGH);
  digitalWrite(quarto2, !HIGH);
  digitalWrite(banheiro, !HIGH);
  digitalWrite(luzGaragem, !HIGH);
  digitalWrite(luzExterna, !HIGH);
  digitalWrite(luzVerde, !HIGH);
  digitalWrite(luzCentral, !HIGH);
  digitalWrite(quintal, !HIGH);
  digitalWrite(ventilador, !HIGH);
}

void loop() {

  if (bluetooth.available()) {
    z = bluetooth.read();

   ///////////////////Luz garagem///////////////////////////
  if (z == 'F')digitalWrite(luzGaragem, !LOW);
  if (z == 'f')digitalWrite(luzGaragem, !HIGH);
  
  ////////////////////Luz Central////////////////////////
  if (z == 'A')digitalWrite(luzCentral, !LOW);
  if (z == 'a')digitalWrite(luzCentral, !HIGH);
  
  /////////////////////Luz Verde////////////////////////
  if (z == 'B')digitalWrite(luzVerde, !LOW);
  if (z == 'b')digitalWrite(luzVerde, !HIGH);

  //////////////////////Luz cozinha////////////////////////
  if (z == 'D')digitalWrite(cozinha, !LOW);
  if (z == 'd')digitalWrite(cozinha, !HIGH);
  
  /////////////////////Luz quarto 1/////////////////////////
  if (z == 'E')digitalWrite(quarto1, !LOW);
  if (z == 'e')digitalWrite(quarto1, !HIGH);
  
  //////////////////////Luz quarto 2///////////////////////////
  if (z == 'G')digitalWrite(quarto2, !LOW);
  if (z == 'g')digitalWrite(quarto2, !HIGH);
  
  //////////////////////Luz banheiro/////////////////////////////
  if (z == 'H')digitalWrite(banheiro, !LOW);
  if (z == 'h')digitalWrite(banheiro, !HIGH);
  
  ///////////////////////Luz quintal/////////////////////////////
  if (z == 'J')digitalWrite(quintal, !LOW);
  if (z == 'j')digitalWrite(quintal, !HIGH);

  ////////////////////////ventilador/////////////////////////
  if (z == 'L')digitalWrite(ventilador, !LOW);
  if (z == 'l')digitalWrite(ventilador, !HIGH);
  
  ///////////////////////Luz externa/////////////////////
  if (z == 'P')digitalWrite(luzExterna, !LOW);
  if (z == 'p')digitalWrite(luzExterna, !HIGH);

  /////////////////////Desligar todas as luzes/////////////////////////
  if (z == 'K') {
    digitalWrite(luzGaragem, !LOW);
    digitalWrite(luzExterna, !LOW);
    digitalWrite(luzVerde, !LOW);
    digitalWrite(luzCentral, !LOW);
    digitalWrite(quintal, !LOW);
    digitalWrite(banheiro, !LOW);
    digitalWrite(quarto1, !LOW);
    digitalWrite(cozinha, !LOW);
    digitalWrite(quarto2, !LOW);
  }
  //////////////////////Ligar todas as luzes/////////////////////////////
  if (z == 'k') {
    digitalWrite(luzGaragem, !HIGH);
    digitalWrite(luzExterna, !HIGH);
    digitalWrite(luzVerde, !HIGH);
    digitalWrite(luzCentral, !HIGH);
    digitalWrite(quintal, !HIGH);
    digitalWrite(banheiro, !HIGH);
    digitalWrite(quarto1, !HIGH);
    digitalWrite(cozinha, !HIGH);
    digitalWrite(quarto2, !HIGH);
  }

  delay(500);
  }
 
}
