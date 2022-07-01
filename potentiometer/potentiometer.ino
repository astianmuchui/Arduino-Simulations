int value;
int led = 9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Initializing.......");
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0);
  value = map(value,0,1023,0,255);
  analogWrite(led,value);
  Serial.println(value);
  delay(500);
}
