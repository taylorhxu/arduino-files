#include <Servo.h>
Servo myservoHand;

const int threshValue = 100;

int tense = 0;
long timer = 0;

void setup()
{
  Serial.begin(9600);
 myservoHand.attach(11);
}


void loop()
{

  float value = analogRead(A0);

  if (value<= threshValue){
    tense = 1;
    myservoHand.write(180);
    timer = millis();
  }

  else if (value > threshValue){
    if((millis()-timer)>=10){
    tense = 0;
    myservoHand.write(0);
    }
  }


  Serial.println(tense);
  //Serial.println(value);

  
}
