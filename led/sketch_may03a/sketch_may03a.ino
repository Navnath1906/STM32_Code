 void setup() {
  pinmode(D4,OUTPUT);

}

void loop() {
  digitalwrite(D4,HIGH);
  delay(1000);
  digitalwrite(D4,LOW);
  delay(1000);

}
