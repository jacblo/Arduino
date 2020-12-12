void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(A1);
  int y = analogRead(A0);
  String out = String(x/10);// + "," + String(y/10);
  Serial.println(out);
}
