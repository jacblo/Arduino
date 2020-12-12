int data = 0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {

  data = analogRead(1);
 Serial.println(data);

}
