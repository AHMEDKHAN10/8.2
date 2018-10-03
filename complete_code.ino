const int ledPin = 12;
const int ldrPin = A5;
int soundSensor=5;
int LED= 4;
boolean LEDStatus=false;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, INPUT);//for motion sensor
  pinMode(ldrPin, INPUT); // for ldr
  pinMode(ledPin, OUTPUT);// led for for motion and ldr
  pinMode(soundSensor,INPUT);//sound sensor
  pinMode(LED,OUTPUT);// led for sound sensor

}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrStatus = analogRead(ldrPin);
  if (digitalRead(7) == HIGH && ldrStatus <=200)
  {
      Serial.println("Active");
      digitalWrite(ledPin, HIGH); 
      delay(5000); 
      Serial.print("Its DARK, lights should turn on as there is motion ");  
   
  }
  else if (digitalRead(7) == HIGH && ldrStatus >= 200)
  {
      Serial.println("Active");
      Serial.print("Its BRIGHT, no need of artificial light ");
      digitalWrite(ledPin, LOW);  
       
  }
  
else if(digitalRead(7) == LOW && ldrStatus >= 200)
{
    Serial.println("Inactive");
    Serial.print("Its BRIGHT, Turn off the LED : ");
    digitalWrite(ledPin, LOW);  
 }
 else if(digitalRead(7) == LOW && ldrStatus <= 200)
 {
    Serial.println("Inactive");
    Serial.print("Its DARK, but no need of light as there is no motion");
    digitalWrite(ledPin, LOW);  
 }
 int SensorData=digitalRead(soundSensor); 
  if(SensorData == 1)
    {
      if(LEDStatus==false)
      //if (soundSensor=HIGH)
      {
        LEDStatus=true;
        digitalWrite(LED,HIGH);
     
        //digitalWrite(LED,LOW);
        Serial.println("SOUND DETECTED FROM FLUSH");
      }
   else
    {
        LEDStatus=false;
        digitalWrite(LED,LOW);
     }
   }
   delay(1000);
 } 
