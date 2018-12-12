void setup() {
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

bool f(int val, int offset) {
  int t = (val >> 2) + offset;
  return (t & 0x7) >= 3;
}

void loop() {
  digitalWrite(4, f(millis(), 0));
  digitalWrite(5, f(millis(), 4));
  digitalWrite(6, f(millis(), 2));
  digitalWrite(7, f(millis(), 6));
}
