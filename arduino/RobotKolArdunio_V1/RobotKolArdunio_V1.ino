#include <Servo.h>


Servo servoDonme;
Servo ServoOmuzic;

Servo ServoOmudis;

Servo ServoDirsek;

Servo ServoTutkac;
Servo ServoBilek;
char karakter;
bool ilk=true;

int aci;


void setup(){
  Serial.begin(9600);
  servoDonme.attach(3);
  ServoOmuzic.attach(4);
  ServoOmudis.attach(5);
ServoDirsek.attach(6);
ServoTutkac.attach(8);
  ServoBilek.attach(7);
}

void loop(){
  
if(ilk==true)
{
  ServoOmuzic.write(90);
ServoOmudis.write(90);
servoDonme.write(90);
ServoDirsek.write(180);
ServoBilek.write(150);
ilk=false;
  }

karakter=Serial.read();
  if(karakter=='D')
  {
aci=Serial.parseInt();
servoDonme.write(aci);
    }


 else if(karakter=='O')
  {
aci=Serial.parseInt();
ServoOmuzic.write(aci);
ServoOmudis.write(aci);
   }

  else if(karakter=='R')
  {
aci=Serial.parseInt();
ServoDirsek.write(aci);

   }
     else if(karakter=='T')
  {
aci=Serial.parseInt();
ServoTutkac.write(aci);

   }  else if(karakter=='B')
  {
    aci=Serial.parseInt();
    ServoBilek.write(aci);

   }
}

