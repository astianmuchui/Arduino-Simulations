void setup(){
// this code runs once
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);

}
void loop(){
// this code runs repeatedly

  // make l led glow
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13,LOW);
  delay(100);


  // Make Connected LED GLOW
  digitalWrite(12,HIGH);
  delay(100);
  digitalWrite(12,LOW);
  delay(100);
}
