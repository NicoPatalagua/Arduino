int val = 7; //laser attach to 
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the photo interrupter sensor interface

void setup ()
{
  Serial.begin(9600);
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// define the photo interrupter sensor output interface 
  pinMode(val, OUTPUT);  
}
void loop ()
{
  val = digitalRead (buttonpin) ;
  Serial.println(val);
  if (val == HIGH) // When the light sensor detects a signal is interrupted, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}