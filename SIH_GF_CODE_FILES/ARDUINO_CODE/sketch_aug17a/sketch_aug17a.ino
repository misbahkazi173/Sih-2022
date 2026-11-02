int led=5;
int pi4=11;

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(pi4,INPUT);
}
void loop()
{
  if(pi4==HIGH)
  {
    Serial.print("led ON");
    digitalWrite(led,HIGH);
  }

  else
  {
   Serial.print("led Off");
   digitalWrite(led,LOW);
  }
}