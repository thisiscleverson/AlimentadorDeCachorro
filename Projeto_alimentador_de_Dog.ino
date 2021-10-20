//--------------------------[bibliotecas]----------------------//
#include "NewPing.h"
#include "Servo.h"

//--------------------------[definições]----------------------//
#define pinTrig 8       // pino do sensor ultrassônico [Trig]
#define pinEcho 9        // pino do sensor ultrassônoco [Echo]
#define distanciaMax 200 // distancia maxima do sensor

#define PinServo 10      // pino do servo motor
#define aproximacao 10   // definição de aproximação do sensor ultrassônico

#define tempoDeAbertura 1000 // tempo em que a tampa vai ficar aberta
#define tempoDeExeculcao 10000 // tempo para ser execultado novamente

#define led 4

NewPing sensor(pinTrig,pinEcho,distanciaMax);
Servo meuServo;

void setup() {
  Serial.begin(9600);
  meuServo.attach(PinServo); // configurar o pino do servo motor
  meuServo.write(0);// iniciar o servo com o angulo 0


  pinMode(led,OUTPUT);

  /*
  digitalWrite(led,HIGH);
  delay(300);
  digitalWrite(led,LOW);*/
 

}

void loop() {
  Serial.println(sensor.ping_cm());
  delay(100);

  if(sensor.ping_cm() <= aproximacao){
     meuServo.write(180);  // mudar a posição do angulo do servo para 180°
     digitalWrite(led,1); // ligar o led
     
     Serial.println("servo em 180°");
     delay(tempoDeAbertura); // esperar um tempo para fechar a tampa
     
     meuServo.write(0); // mudar a posição do angulo do servo para 0°
     digitalWrite(led,0); // ligar o led
     
     Serial.println("servo em 0°");
     delay(tempoDeExeculcao);

     /*
     while(sensor.ping_cm() <= aproximacao){
      delay(1000);
      }*/
   }
}//end loop
