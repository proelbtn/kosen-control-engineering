#define SPD 3
#define IN1 4
#define IN2 5

#define CW 1
#define CCW 2

#define Kp 0.015
#define Ki 0.02
#define Kd 0.01

float err_acc;
float err_prev;

void changeSpeed(unsigned char speed) {
  analogWrite(SPD, speed);
}

void changeMode(int mode) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  delay(1);
  
  if (mode == CW) digitalWrite(IN1, HIGH);
  else if (mode == CCW) digitalWrite(IN2, HIGH);

  err_acc = 0;
  err_prev = 0;
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  float now = (analogRead(0) - 512) / 512. * 160.;
  float target = (analogRead(1) - 512) / 512. * 150.;

  float err = (now - target);
  err_acc += err;
  
  float pv = Kp * err;
  float iv = Ki * err_acc;
  float dv = Kd * (err - err_prev);

  float val = pv + iv + dv;


  Serial.print(analogRead(0));
  Serial.print(",");
  Serial.print(analogRead(1));
  Serial.print(",");
  Serial.print(val * 20);
  Serial.print(",");
  Serial.println(err_acc);
  
  

  if (val < 0) {
    changeMode(CW);
    val = -val;
  }
  else changeMode(CCW);

  changeSpeed(val * 20);
  delay(1);
 
}
