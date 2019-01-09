typedef void(*func_t)();

#define MODE 3

#define IN1 1
#define IN2 2

#define CW 1
#define CCW 2

func_t func;

void changeSpeed(unsigned char speed) {
  analogWrite(3, speed);
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
  
  switch (MODE) {
    case 1: func = task1; break;
    case 2: func = task2; break;
    case 3: func = task3; break;
  }
}

void loop() {
  func();
}

void task1() {
  changeSpeed(127);
  
  changeMode(CW);
  delay(3000);
  changeMode(CCW);
  delay(3000);
}

void task2() {
  int step = 10000 / 256;

  changeMode(CW);
  
  for (int i = 0; i < 256; i++) {
    changeSpeed(i);
    delay(step);
  }

  for (int i = 0; i < 256; i++) {
    changeSpeed(255 - i);
    delay(step);
  }
}

void task3() {
  static unsigned int prev_mode = CW;
  
  unsigned int val = analogRead(0), speed, mode;

  speed = val < 512 ? (511 - val) >> 1 : (val - 512) >> 1;
  mode = val < 512 ? CW : CCW;

  changeSpeed(speed);
  if (prev_mode != mode) {
    changeMode(mode);
    prev_mode = mode;
  }
}
