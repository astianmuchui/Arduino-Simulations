int led = 10;
int button = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(9, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button)==0){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
  }else{
    digitalWrite(led,LOW);
    delay(500);
  }
}
