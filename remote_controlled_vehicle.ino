int in1 = 6;  //Right engine
int in2 = 7;
int in3 = 8;  //Left engine
int in4 = 9;
int buttonA = 5;  //D2
int buttonB = 4;  //D0
int buttonC = 3;  //D3
int buttonD = 2;  //D1
int leftTrack = 10;
int rightTrack = 11;
int x = 0;// 0- mode mobile slow; 1- mode mobile fast
int y = 0;// 0- mode mobile; 1- mode individual

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(leftTrack, OUTPUT);
  pinMode(rightTrack, OUTPUT);
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buttonC, INPUT_PULLUP);
  pinMode(buttonD, INPUT_PULLUP);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  //change mode individual-mobile
  if (y == 0 && digitalRead(buttonB) == HIGH && digitalRead(buttonD) == HIGH) {
    y = 1;
    delay(1000);
  }
  if (y == 1 && digitalRead(buttonB) == HIGH && digitalRead(buttonD) == HIGH) {
    y = 0;
    delay(1000);
  }
  //mode mobile:fast-slow
  if (y == 0 && x == 0 && digitalRead(buttonB) == HIGH && digitalRead(buttonC) == HIGH) {
    x = 1;
    delay(1000);
  }
  if (y == 0 && x == 1 && digitalRead(buttonB) == HIGH && digitalRead(buttonC) == HIGH) {
    x = 0;
    delay(1000);
  }
  //mode mobile slow
  if (x == 0 && y == 0) {
    // forward
    if (digitalRead(buttonA) == HIGH) {
      analogWrite(leftTrack, 212);
      analogWrite(rightTrack, 212);
      digitalWrite(in2, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in4, LOW);
      digitalWrite(in3, HIGH);
    }
    // backward
    else if (digitalRead(buttonD) == HIGH) {
      analogWrite(leftTrack, 227);
      analogWrite(rightTrack, 200);
      digitalWrite(in2, LOW);
      digitalWrite(in1, HIGH);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
    }
    //turn right
    else if (digitalRead(buttonB) == HIGH) {
      analogWrite(leftTrack, 216);
      analogWrite(rightTrack, 205);
      digitalWrite(in2, LOW);
      digitalWrite(in1, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

    }
    //turn left
    else if (digitalRead(buttonC) == HIGH) {
      analogWrite(leftTrack, 222);
      analogWrite(rightTrack, 210);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
    }
  }
  //mode mobile fast
  if (x == 1 && y == 0) {
    // forward
    if (digitalRead(buttonA) == HIGH) {
      analogWrite(leftTrack, 244);
      analogWrite(rightTrack, 247);
      digitalWrite(in2, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in4, LOW);
      digitalWrite(in3, HIGH);
    }
    // backward
    else if (digitalRead(buttonD) == HIGH) {
      analogWrite(leftTrack, 250);
      analogWrite(rightTrack, 235);
      digitalWrite(in2, LOW);
      digitalWrite(in1, HIGH);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
    }
    // turn right
    else if (digitalRead(buttonB) == HIGH) {
      analogWrite(leftTrack, 246);
      analogWrite(rightTrack, 235);
      digitalWrite(in2, LOW);
      digitalWrite(in1, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    //turn left
    else if (digitalRead(buttonC) == HIGH) {
      analogWrite(leftTrack, 252);
      analogWrite(rightTrack, 240);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
    }
  }
  //mode individual
  if (y == 1) {
    //left track forward
    if (digitalRead(buttonA) == HIGH && digitalRead(buttonC) == LOW) {
      analogWrite(leftTrack, 216);
      digitalWrite(in4, LOW);
      digitalWrite(in3, HIGH);
    }
    // right track backword
    if (digitalRead(buttonD) == HIGH && digitalRead(buttonB) == LOW) {
      analogWrite(rightTrack, 200);
      digitalWrite(in2, LOW);
      digitalWrite(in1, HIGH);
    }
    // right track forward
    if (digitalRead(buttonB) == HIGH && digitalRead(buttonD) == LOW) {
      analogWrite(rightTrack, 212);
      digitalWrite(in2, HIGH);
      digitalWrite(in1, LOW);
    }
    //left track backward
    if (digitalRead(buttonC) == HIGH && digitalRead(buttonA) == LOW) {
      analogWrite(leftTrack, 222);
      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
    }
  }
  // when no button is pressed, disconnect power to the motors
  if (digitalRead(buttonA) == LOW && digitalRead(buttonB) == LOW && digitalRead(buttonC) == LOW && digitalRead(buttonD) == LOW) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  delay(30);
}