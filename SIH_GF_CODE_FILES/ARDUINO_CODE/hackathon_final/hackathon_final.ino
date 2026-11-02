int IR_1 = A0;  // connect ir sensor module to Arduino pin 1
int IR_2 = A2;  // connect ir sensor module to Arduino pin 2
int IR_3 = A4;
long Time;
int distance;// connect ir sensor module to Arduino pin 3

int m_1 = 8; // conect LED to Arduino pin 7
int m_2 = 9; // conect LED to Arduino pin 8
int m_3 = 10;// conect LED to Arduino pin 9
int m_4 = 11;// conect LED to Arduino pin 10
int trig_Pin=6;
int echo_Pin=7;


void setup()
{
  Serial.begin(9600); // Init Serila at 115200 Baud
  Serial.println("Serial Working"); // Test to check if serial is working or not
  pinMode(IR_1, INPUT); // IR Sensor pin INPUT 1
  pinMode(IR_2, INPUT); // IR Sensor pin INPUT 2
  pinMode(IR_3, INPUT); // IR Sensor pin INPUT 3
  pinMode(m_1, OUTPUT);//motor in 1
  pinMode(m_2, OUTPUT);//motor in 2
  pinMode(m_3, OUTPUT);//motor in 3
  pinMode(m_4, OUTPUT);//motor in 4
  pinMode(trig_Pin,OUTPUT);
  pinMode(echo_Pin,INPUT);
}
void loop()
{
  int sensor_1= analogRead(IR_1); // Set the GPIO as Input
  int sensor_2= analogRead(IR_2); // Set the GPIO as Input
  int sensor_3= analogRead(IR_3); // Set the GPIO as Input
  digitalWrite(trig_Pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_Pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin,LOW);
  Time=pulseIn(echo_Pin,HIGH);
  distance=Time*0.034/2;
  Serial.print("Distance:");
  Serial.println(distance);
  if(distance>15)
  {
    if (sensor_1 <500)// Check if the pin high or not
    {
  
      analogWrite(m_1, 200);
      analogWrite(m_2, 0);
      analogWrite(m_3, 0);
      analogWrite(m_4, 200);
      Serial.println("RIGHT");
      }// print Motion Detected! on the serial monitor window
    else
    {
      analogWrite(m_1, 0);
      analogWrite(m_2, 0);
      analogWrite(m_3, 0);
      analogWrite(m_4, 0);
      }// Serial.println("Motion Ended!"); // print Motion Detected! on the serial monitor window
    if (sensor_2 <500)// Check if the pin high or not
    {
      analogWrite(m_1,  0);
      analogWrite(m_2, 200);
      analogWrite(m_3,  0);
      analogWrite(m_4, 200);
      Serial.println("FORWARD");
      }// print Motion Detected! on the serial monitor window
    else
    {
      analogWrite(m_1, 0);
      analogWrite(m_2, 0);
      analogWrite(m_3, 0);
      analogWrite(m_4, 0);
      }// Serial.println("Motion Ended!"); // print Motion Detected! on the serial monitor window
    if (sensor_3 <500) // Check if the pin high or not
    {
      analogWrite(m_1, 0);
      analogWrite(m_2, 200);
      analogWrite(m_3, 200);
      analogWrite(m_4, 0);
      Serial.println("LEFT");
      } // print Motion Detected! on the serial monitor window
    else
    {
      analogWrite(m_1, 0);
      analogWrite(m_2, 0);
      analogWrite(m_3, 0);
      analogWrite(m_4, 0);
      Serial.println("Motion Ended!");
      }// // print Motion Detected! on the serial monitor window
  }
}