#include <Servo.h>
#include <NewPing.h>
char data;
int PWMControl_L = 5;
int PWMControl_R = 6;
int PWM_Value = 0;
#define trigPin 10
#define echoPin 8
long duration;
float distanceInch;
int timer;


void setup()
{
Serial.begin(9600);
pinMode(3, OUTPUT);
pinMode(9, OUTPUT);
pinMode(PWMControl_L, OUTPUT);
pinMode(PWMControl_R, OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(11,OUTPUT);}


void proximity(){
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distanceInch = duration * 0.04 /2;
Serial.println(distanceInch);

if(distanceInch<20){
digitalWrite(11, HIGH);
delay(50);
digitalWrite(11, LOW);

timer = distanceInch * 10;

delay(timer);}
}//void proximity

void basicControls(){
  if(data == '1') // forward
{
analogWrite(PWMControl_L, PWM_Value);
digitalWrite(3, LOW);
digitalWrite(9, HIGH);               
analogWrite(PWMControl_R, PWM_Value);
Serial.println("Forward");


}

if(data == '2') //forward stop
{
analogWrite(PWMControl_L, PWM_Value);
digitalWrite(3, LOW);
digitalWrite(9, LOW);
analogWrite(PWMControl_R, PWM_Value);
   
}

if(data == '3') //backward
{
analogWrite(PWMControl_L, PWM_Value);
digitalWrite(3, HIGH);
digitalWrite(9, LOW);
analogWrite(PWMControl_R, PWM_Value);
Serial.println("Backward");
}

if(data == '4') //backward stop
{
analogWrite(PWMControl_L, PWM_Value);
digitalWrite(3, LOW);
digitalWrite(9, LOW);
analogWrite(PWMControl_R, PWM_Value);
}

if(data == '5') //right
{
analogWrite(PWMControl_L, PWM_Value);
digitalWrite(3, LOW);
digitalWrite(9, HIGH);
digitalWrite(PWMControl_R,LOW);
Serial.println("right");

}

if(data == '6')//right stop
{
analogWrite(PWMControl_L, PWM_Value);
digitalWrite(3, LOW);
digitalWrite(9, LOW);
analogWrite(PWMControl_R, PWM_Value);
}

if(data == '7') //left
{
digitalWrite(PWMControl_L, LOW);
digitalWrite(3, LOW);
digitalWrite(9, HIGH);
analogWrite(PWMControl_R, PWM_Value);
Serial.println("Left");

}

if(data == '8')// left stop
{
analogWrite(PWMControl_L, PWM_Value);
digitalWrite(3, LOW);
digitalWrite(9, LOW);
analogWrite(PWMControl_R, PWM_Value);
}

if(data == '9') //stop
{
digitalWrite(PWMControl_L, LOW);
digitalWrite(3, LOW);
digitalWrite(9, LOW);
digitalWrite(PWMControl_R, LOW);
Serial.println("stop");

}
if(data == '0')// stop stop
{
analogWrite(PWMControl_L, PWM_Value);
digitalWrite(3, LOW);
digitalWrite(9, LOW);
analogWrite(PWMControl_R, PWM_Value);
}

if(data == 'H')// horn 
{
digitalWrite(11,HIGH);
}
if(data == 'J')// horn stop
{
digitalWrite(11,LOW);}
                     
  }// end void basicControls

void speedControl() {
  if(data == 'S'){
  PWM_Value=650;
  PWM_Value = map(PWM_Value,0,1023,0,255);
  }
else if(data == 'M'){
  PWM_Value=800;
  PWM_Value = map(PWM_Value,0,1023,0,255);
  }
else if(data == 'F'){
  PWM_Value=1023;
  PWM_Value = map(PWM_Value,0,1023,0,255);}
  }


void accControls() {
                                 
if(data == 'Z') // forward
{
digitalWrite(PWMControl_L, HIGH);
digitalWrite(3, LOW);
digitalWrite(9, HIGH);
digitalWrite(PWMControl_R, HIGH);
Serial.println("Forward");

}

if(data == 'B') //backward
{
digitalWrite(PWMControl_L, HIGH);
digitalWrite(3, HIGH);
digitalWrite(9, LOW);
digitalWrite(PWMControl_R, HIGH);
Serial.println("Backward");
}

if(data == 'R') //right
{
digitalWrite(PWMControl_L, HIGH);
digitalWrite(3, LOW);
digitalWrite(9, HIGH);
digitalWrite(PWMControl_R, LOW);
Serial.println("right");}

if(data == 'L') //left
{
digitalWrite(PWMControl_L, LOW);
digitalWrite(3, LOW);
digitalWrite(9, HIGH);
digitalWrite(PWMControl_R, HIGH);
Serial.println("Left");}
} // end void accControls






  
void loop()
{

    
//proximity();   
                          
if(Serial.available() > 0){
data = Serial.read();
Serial.print(data);
Serial.print("\n");  

speedControl();                        
basicControls();
accControls();                               


                       

}// end serial call
}// end loop
