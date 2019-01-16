#define SPD 3
#define IN1 4
#define IN2 5

#define CW 1
#define CCW 2

#define Kp 0.03

void changeSpeed(unsigned char speed) {
  analogWrite(SPD, speed);
}

void changeMode(int mode) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  delay(1);
  
  if (mode == CW) digitalWrite(IN1, HIGH);
  else if (mode == CCW) digitalWrite(IN2, HIGH);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  changeSpeed(150);

  float now = (analogRead(0) - 512) / 512. * 160.;
  float target = (analogRead(1) - 512) / 512. * 150.;

  float val = Kp * (now - target);

  if (val < 0) {
    changeMode(CW);
    val = -val;
  }
  else changeMode(CCW);

  changeSpeed(val * 20);
  
  Serial.print(analogRead(0));
  Serial.print(",");
  Serial.print(analogRead(1));
  Serial.print(",");
  Serial.println(val * 20);

  delay(10);
}
