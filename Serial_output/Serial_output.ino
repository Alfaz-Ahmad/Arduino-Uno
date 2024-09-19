// C++ code
//

int j = 1;
int time = 1000;

void setup()
{
 	Serial.begin(9600);
}

void loop()
{
  	Serial.print("j = ");
  	Serial.println(j);
  	j = j+1;
	delay(time);
}