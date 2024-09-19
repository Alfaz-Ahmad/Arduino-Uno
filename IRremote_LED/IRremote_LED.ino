#include<IRremote.h>

int receiver = 8;  
int Redled= 7;
bool LED = true;
unsigned long press;

IRrecv irrecv(receiver);

void setup()                 
{
  pinMode(Redled,OUTPUT); 
  digitalWrite(Redled, HIGH);   
  Serial.begin(9600);
  irrecv.enableIRIn();                       
}

void loop()                              
{
  if (irrecv.decode()){
    press = irrecv.decodedIRData.decodedRawData;
    Serial.println(press);  
    if(press == 3910598400){
      if(LED){
        digitalWrite(Redled, LOW);
        LED = !LED;
      }else{
        digitalWrite(Redled, HIGH);
        LED = !LED;
      }
    }
    irrecv.resume();
  }
}
