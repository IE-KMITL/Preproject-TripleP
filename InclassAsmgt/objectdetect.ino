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
// ในช่วงแรก LED ตรวจพบกระดาษขาวในระยะมากกว่า15 cm ซึ่งสามารถแก้ไขได้โดยใช้ไขควงไขทำให้ LED สามารถตรวจพบกระดาษขาวได้ในระยะ 15 cm ดับเมื่อตรวจไม่พบหรือวัตถุอยู่ไกลกว่า 15 cm และเมื่อทดลองกับวัตถุชนิดต่างๆ 5 ชนิดได้แก่ 
// ฝากล่องพลาสติกสีขาว 8 cm, กระเป๋าสตางค์สีเนื้อ 13 cm,เครื่องคิดเลขสีดำ 5 cm, จานพลาสติกสีส้ม 11 cm,แฟ้มใสสีเขียว 14 cm
// จะเห็นว่าวัตถุสีขาวใสสะท้อนคลื่นสัญญาณ infraredได้ดีกว่าสีอื่นและเป็นลักษณะสีทึบ
