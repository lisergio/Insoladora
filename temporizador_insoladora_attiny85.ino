/*
 *---------------*
 |DIL 8 | Arduino|
 |------|--------|
 |  1   |        | reset 
 |  2   |   3    | Analog in / digial in or out
 |  3   |   4    | Analog in / digial in or out
 |  4   |        | GND
 |  5   |   0    | PWM / digial in or out
 |  6   |   1    | PWM / digial in or out
 |  7   |   2    | Analog in / digial in or out
 |  8   |        | VCC
 *---------------*
 */
 
 
#define SALIDA_PIN 3 
#define LED1_PIN 0 
#define LED2_PIN 1
#define PULSADOR1_PIN 2
#define PULSADOR2_PIN 4


int tiempo=120;
boolean estado_pulsador_1=0;
boolean estado_pulsador_2=0;
boolean tiempo_iniciado=0;

void setup()
{
  pinMode(SALIDA_PIN,OUTPUT);
  pinMode(LED1_PIN,OUTPUT);
  pinMode(LED2_PIN,OUTPUT);
  pinMode(PULSADOR1_PIN,INPUT);
  pinMode(PULSADOR2_PIN,INPUT);
}

void loop()
{
  if(tiempo==100)
  {
    digitalWrite(LED1_PIN,LOW);
    digitalWrite(LED2_PIN,LOW);
  }

  if(tiempo==120)
  {
    digitalWrite(LED1_PIN,HIGH);
    digitalWrite(LED2_PIN,LOW);
  }

  if(tiempo==140)
  {
    digitalWrite(LED1_PIN,LOW);
    digitalWrite(LED2_PIN,HIGH);
  }

  if(tiempo==160)
  {
    digitalWrite(LED1_PIN,HIGH);
    digitalWrite(LED2_PIN,HIGH);
  }

  
  estado_pulsador_1=digitalRead(PULSADOR1_PIN);
  estado_pulsador_2=digitalRead(PULSADOR2_PIN);
 
 if (estado_pulsador_1==LOW)
 {
   tiempo=tiempo+20;
  if (tiempo==180)
  {
    tiempo=100;
  } 
  delay(250);
 } 

 if (estado_pulsador_2==LOW)   
 {
    tiempo_iniciado=1;
    digitalWrite(SALIDA_PIN,HIGH);
    while (tiempo_iniciado==1)
    {
      digitalWrite(LED1_PIN,HIGH);
      digitalWrite(LED2_PIN,HIGH);
      delay(526);
      digitalWrite(LED1_PIN,LOW);
      digitalWrite(LED2_PIN,LOW);
      delay(526);
      tiempo=tiempo--;
      if (tiempo==0)
      {
        tiempo_iniciado=0;
        digitalWrite(SALIDA_PIN,LOW);
        tiempo=120;
      }
      
    }
 }
}
