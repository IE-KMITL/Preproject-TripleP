int led = D2;
int sensor = D4;
int val = 0;
void setup() {
  pinMode(led, OUTPUT);  
  pinMode(sensor, INPUT); 
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(sensor);  
  Serial.print("val = "); 
  Serial.println(val); 
  if (val == 0) { 
    digitalWrite(led, HIGH); 
  }
  else {
    digitalWrite(led, LOW); 
  }
  delay(100);
}
