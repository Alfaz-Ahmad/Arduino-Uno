#include <IRremote.h>      

int RECV_PIN = 8;        
IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}
 
void loop() 
{
  if (irrecv.decode()) 
    {
    int value = results.value;
    Serial.println(" ");
    // Serial.print("Code: ");
    Serial.println(results.value); 
    Serial.println(" ");
    irrecv.resume();              
    // Serial.println("*****************");
    }
}