#define ia1 25 
#define ia2 16 
#define ib1 26 
#define ib2 17 
#define ic1 27
#define ic2 14
#define id1 12
#define id2 13
#define sensor1 18 //left
#define sensor2 19 //front
#define sensor3 23 //back
#define sensor4 05 //right
#define color 36 //จับสี
#define swith 39  // สวิซต์
#define maxSpd 255
int speed = maxSpd;
int led;
int t=0;
int r=0;

void setup() { 
  pinMode(ia1, OUTPUT);
  pinMode(ia2, OUTPUT);
  pinMode(ib1, OUTPUT);
  pinMode(ib2, OUTPUT);
  pinMode(ic1, OUTPUT);
  pinMode(ic2, OUTPUT);
  pinMode(id1, OUTPUT);
  pinMode(id2, OUTPUT);
  pinMode(swith, INPUT);
  pinMode(color,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  Serial.begin(9600);
}
void loop() { 
 if (led==HIGH){
  Challenger();
 }
 if(led == LOW){
  defend();
 }
}
void defend(){
  Dsensor1();
  Dsensor2();
  Dsensor3();
  }
 void Challenger(){
  Csensor2();
  Csensor1();
  Csensor4();
  SensorcolorR();
  Csensor3();
 }
 void Forward(int speed) //goforward
{
  digitalWrite(ia1, LOW);   
  analogWrite(ia2, speed);   
  digitalWrite(ib1, LOW);   
  analogWrite(ib2, speed); 
  digitalWrite(ic1, LOW);   
  analogWrite(ic2, speed); 
  digitalWrite(id1, LOW);   
  analogWrite(id2, speed); 
  }
void Reward(int speed) //goReward
{
  digitalWrite(ia2, LOW);   
  analogWrite(ia1, speed);   
  digitalWrite(ib2, LOW);   
  analogWrite(ib1, speed); 
  digitalWrite(ic2, LOW);   
  analogWrite(ic1, speed); 
  digitalWrite(id2, LOW);   
  analogWrite(id1, speed); 
  }
void TurnLeft(int speed) //Turnleft
{
  digitalWrite(ia1, LOW);   
  analogWrite(ia2, 0.8*speed);   
  digitalWrite(ib1, LOW);   
  analogWrite(ib2, 0.3*speed); 
  digitalWrite(ic1, LOW);   
  analogWrite(ic2, 0.8*speed); 
  digitalWrite(id1, LOW);   
  analogWrite(id2, 0.3*speed); 
}
void TurnRight(int speed) //TurnRight
{
  digitalWrite(ia1, LOW);   
  analogWrite(ia2, 0.3*speed);   
  digitalWrite(ib1, LOW);   
  analogWrite(ib2, 0.8*speed); 
  digitalWrite(ic1, LOW);   
  analogWrite(ic2, 0.3*speed); 
  digitalWrite(id1, LOW);   
  analogWrite(id2, 0.8*speed); 
}
void Break() // motor break
{
  digitalWrite(ia1, HIGH);   
  digitalWrite(ia2, HIGH);  
  digitalWrite(ib1, HIGH);   
  digitalWrite(ib2, HIGH); 
  digitalWrite(ic1, HIGH);   
  digitalWrite(ic2, HIGH);   
  digitalWrite(id1, HIGH);   
  digitalWrite(id2, HIGH);  
}
void Dsensor1(){ //sensor1+defend
    int speed = maxSpd;
  if(digitalRead(sensor1)==LOW){
        delay(20);   
        if(t<=300){
          Forward(speed);
          delay(10);
          t++;
        }
        if(t==300 && r<=300){
          Reward(speed);
          delay(10);
          r++;
        }
        if(t==300 && r==300){
          t=0;
          r=0;
        }
       } 
   else{
    Break();
   }
}
 void Dsensor2(){
  int speed = maxSpd;
  int sensorvalue = analogRead(A0);
  if(digitalRead(sensor2)==LOW){
        delay(20); 
        Forward(speed);
   }
  if(digitalRead(sensor2)==LOW && sensorvalue >=3600&&sensorvalue <=3900){
        delay(20); 
        Reward(speed);
   }
  if(digitalRead(sensor2)==HIGH){
        delay(20); 
        Break();
  }
 }
 void Dsensor3(){
  int speed = maxSpd;
  int sensorvalue = analogRead(A0);
  if(digitalRead(sensor3)==LOW){
        delay(20); 
        Reward(speed);
   }
  if(digitalRead(sensor3)==LOW && sensorvalue >=3600&&sensorvalue <=3900){
        delay(20); 
        Forward(speed);
   }
  if(digitalRead(sensor3)==HIGH){
        delay(20); 
        Break();
   }
 }
 void Csensor2(){
  int speed = maxSpd;
  if(digitalRead(sensor2)==LOW){
        delay(20); 
        Reward(speed);
   }
  else{
    Forward(speed);
    }
 }
 void Csensor1(){
  int speed = maxSpd;
  if(digitalRead(sensor1)==LOW){
        delay(20); 
       TurnRight(speed);
   }
  else {
    Forward(speed);
    }
 }
 void Csensor4(){
  int speed = maxSpd;
  if(digitalRead(sensor4)==LOW){
        delay(20); 
       TurnLeft(speed);
   }
  else {
    Forward(speed);
    }
 }
 void SensorcolorR(){
  int speed = maxSpd;
  int sensorvalue = analogRead(A0);
  if(sensorvalue>=2200&&sensorvalue<=2500){
        delay(20); 
       Reward(speed);
  }
  else {
    Forward(speed);
    }
 }
 void Csensor3(){
  int speed = maxSpd;
  int sensorvalue = analogRead(A0);
  if(digitalRead(sensor3)==LOW){
       delay(20); 
       Reward(speed);
   }
  if(digitalRead(sensor3)==HIGH){
       delay(20); 
       Forward(speed);
  }
  if(digitalRead(sensor3)==HIGH &&sensorvalue>=2200&&sensorvalue<=2500){
       delay(20); 
       Break();
  }
 }
