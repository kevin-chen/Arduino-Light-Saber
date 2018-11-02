int led1 = 2;
int led2 = 2;
int led3 = 2;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led7 = 7;
int led8 = 8;
int led9 = 9;
int led10 = 12;
int button1 = 3;
int button2 = 13;

int buzzer1 = 10;
int buzzer2 = 11;

int stage = 0;

double future = 0;

int e1 = 41.20;

int a4 = 440.00;
int a4b = 415.30;
int a4s = 466.16;
int b4 = 293.66;
int b4b = 466.16;
int c4 = 261.63;
int d4 = 293.63;
int e4 = 329.63;
int f4 = 349.23;
int f4s = 369.99;
int g4 = 392.00;
int g4s = 415.30;

int a5 = 880.00;
int a5b = 830.61;
int b5 = 987.77;
int c5 = 523.25;
int d5 = 587.33;
int d5b = 554.37;
int e5 = 659.25;
int e5b = 622.25;
int f5 = 698.46;
int g5 = 783.99l;
int g5b = 739.99;

/*
double e1 = 41.20;

double a4 = 440.00;
double a4b = 415.30;
double a4s = 466.16;
double b4 = 293.66;
double b4b = 466.16;
double c4 = 261.63;
double d4 = 293.63;
double e4 = 329.63;
double f4 = 349.23;
double f4s = 369.99;
double g4 = 392.00;
double g4s = 415.30;

double a5 = 880.00;
double a5b = 830.61;
double b5 = 987.77;
double c5 = 523.25;
double d5 = 587.33;
double d5b = 554.37;
double e5 = 659.25;
double e5b = 622.25;
double f5 = 698.46;
double g5 = 783.99l;
double g5b = 739.99;
*/

int bu1 = digitalRead(button1);
int bu2 = digitalRead(button2);

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
}

void loop() {
  long now = millis();
  int bu1 = digitalRead(button1);
  int bu2 = digitalRead(button2);
  
  if (bu1 == 1 && now >= future) {
    future = now + 1000;
    stage ++;
  }

  playSwoosh();
  if (stage == 0) {
    loadingPattern();
    noTone(buzzer1);
  }
  else if (stage == 1) {
    glowing();
    playSwoosh();
    playThemeSong();
  }
  else if (stage == 2) {
    glowing1();
    playSwoosh();
    playImperialMarch();
  }
  else if (stage == 3) {
    glowing2();
    playSwoosh();
    playCantinaBand();
  }
  else {
    stage = 0;
  }
}

//Theme Song
void playThemeSong() {                                            //End of First                                                            //End of Second                                                                              //End of Third                                                            //F Sharp //End of Fourth                                                       //End of Fifth
  int tones[] = {d4,  0,  d4,  0,  d4,  0,  g4,   d5,   c5,  b4,  a4,  g5 ,  d5,  c5,  b4,  a4,  g5,   d5,  c5,  b4,  c5,  a4,   d4,  0,  d4,  0,  g5,   d5,   c5,  b4,  a4,  g5,   d5,  c5,  b4,  a4,  g5,   d5,  c5,  b4,  c5,  a4,   d4,  0,  d4,  0,  e4,  0,  e4,  0,  c5,  b4,  a4,  g4,  0,  g4,  a4,  b4,  a4,  f4s, d4,  0,  d4,  0,  e4,  0,  e4,  0,  c5,  b4,  a4,  g4,  d5,  a4,   d4,  0,  d4,  0};
  int durs[] =  {450, 50, 450, 50, 450, 50, 1000, 1000, 500, 500, 500, 1000, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 1000, 450, 50, 450, 50, 1000, 1000, 500, 500, 500, 1000, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 1000, 450, 50, 450, 50, 950, 50, 950, 50, 500, 500, 500, 500, 50, 500, 500, 500, 500, 500, 450, 50, 450, 50, 950, 50, 950, 50, 500, 500, 500, 500, 500, 1000, 450, 50, 450, 50};
  playTones(buzzer1, tones, durs, 78);
}

//Imperial March
void playImperialMarch() {                         //End of Line One                                                                        //End of Line Two                                                        //End of Line Three                                                                        //End of Line Four
  int tones[] = {a4,  0,  a4,  0,  a4,   f4,  c5,  a4,  f4,   c5,  a4,   e5,  0,  e5,  0,  e5,  f5,  c5,  a4b,  f4,  c5,  a4,   a5,  a4,  0,  a4,  a5,  a5b, g5,  g5b, f5,  g5b, b4b, e5b, d5,  0,  d5b, c5,  b4,  c5,  f4,  a4b, f4,  a4b, c5,  a4,  c5,  e5,   a5,  a4,  0, a4,  a5,  a5b, g5,  g5b, f5,  g5b, b4b, e5b, d5,  d5b};
  int durs[] =  {250, 50, 250, 50, 300, 500, 500, 1000, 500, 500, 1000, 450, 50, 450, 50, 450, 500, 500, 1000, 500, 500, 1000, 300, 250, 50, 300, 300, 500, 300, 300, 300, 500, 500, 500, 450, 50, 450, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 1000, 500, 450, 0, 450, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500};
  playTones(buzzer1, tones, durs, 62);
}

//Cantina Band
void playCantinaBand() {                  //End of Line One                                                           //End of Line Two                                              //End of Line Three                                                       //End of Line Four                                         //End of Line Five
  int tones[] = {a4,  d4,  a4,  d5,  a4,  d5,  a4,  g4s, a4,  a4,  g4s, a4,  g4,  0,   f4s, g4,  f4s, f4,  d4,   0,   a4,  d5,  a4,  d5,  a4,  d5,  a4,  g4s, a4,  g4,  0,  g4,  f4s, g4,  c5,  b4b, a4,  g4,  a4,  d5,  a4,  d5,  a4,  d5,  a4,  g4s, a4,  c5,  0,  c5,  a4,  g4,  f4,   d4,  0,  d4,   f4,   a4,   c5,   e5b, d5,  g4s, a4};
  int durs[] =  {500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 125, 500, 500, 500, 1000, 500, 250, 500, 500, 500, 500, 500, 500, 500, 500, 500, 450, 50, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 450, 50, 500, 500, 500, 1000, 950, 50, 1000, 1000, 1000, 1000, 500, 500, 500, 500};
  playTones(buzzer1, tones, durs, 63);
}

//Swoosh
void playSwoosh() {
  long time = millis()/200;
  int bu1 = digitalRead(button1);
  int bu2 = digitalRead(button2);
  if (bu2 == 1) {
    tone(buzzer2, e1);
    tone(buzzer2, e4);
  }
  else {
    noTone(buzzer2);
  }
}

void playTones(int buzz, int tones[], int durations[], int length) {
  if (sizeof(tones) / sizeof(int) == sizeof(durations) / sizeof(int))
  {
    long sum = 0;
    for (int i = 0; i < length; i++)
    {
      sum += durations[i];
    }
    //calculate which index we should be working with
    int musicI = 0;
    for (musicI = 0; millis() % sum >= sumUntil(durations, musicI, length); musicI++) //super bananas
    {    }
    if (millis() % sum < sumUntil(durations, musicI, length)) //bananas
    {
      playSwoosh();
      if (tones[musicI] != 0)
      {
        playSwoosh();
        tone(buzz, tones[musicI]);
      }
      else
      {
        playSwoosh();
        noTone(buzz);
      }
    }
  }
}

/**
   sumUntil:  returns the sum of all the values from 0 to index
   inside of arr
   This is a helper method for playTones

   Precondtions:  1)  0<=index<=length-1
                  2)  length is the length of arr
*/
long sumUntil(int arr[], int index, int length)
{
  long sum = 0;
  for (int i = 0; i <= index; i++)
  {
    sum += arr[i];
  }
  return sum;
}

//Patterns
void loadingPattern() {
  long now = millis() / 250; //Each light stays on for .25 second
  allLEDsOff();
  playSwoosh();
  if (now % 10 <= 0) { //Quantity of LEDs
    digitalWrite(led1, HIGH);
    digitalWrite(led10, HIGH);
  }
  else if (now % 10 <= 1) {
    digitalWrite(led2, HIGH);
    digitalWrite(led9, HIGH);
  }
  else if (now % 10 <= 2) {
    digitalWrite(led3, HIGH);
    digitalWrite(led8, HIGH);
  }
  else if (now % 10 <= 3) {
    digitalWrite(led4, HIGH);
    digitalWrite(led7, HIGH);
  }
  else if (now % 10 <= 4) {
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  else if (now % 10 <= 5) {
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  else if (now % 10 <= 6) {
    digitalWrite(led4, HIGH);
    digitalWrite(led7, HIGH);
  }
  else if (now % 10 <= 7) {
    digitalWrite(led3, HIGH);
    digitalWrite(led8, HIGH);
  }
  else if (now % 10 <= 8) {
    digitalWrite(led2, HIGH);
    digitalWrite(led9, HIGH);
  }
  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led10, HIGH);
  }
}
void glowing() {
  playSwoosh();
  int length = 1000;
  long mil = millis();
  double g = -127.5 * sin(PI / length * mil) + 127.5;
  all(g);
}
void glowing1() {
  playSwoosh();
  int length = 500;
  long mil = millis();
  double g = -127.5 * sin(PI / length * mil) + 127.5;
  all(g);
}
void glowing2() {
  playSwoosh();
  int length = 250;
  long mil = millis();
  double g = -127.5 * sin(PI / length * mil) + 127.5;
  all(g);
}

void allOn() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);

  int bu1 = digitalRead(button1);
  int bu2 = digitalRead(button2);

  if (bu1 == 0 ) {
    digitalWrite(led9, LOW);
  }
  else if (bu1 == 1) {
    digitalWrite(led9, HIGH);
  }
  if (bu2 == 0 ) {
    digitalWrite(led10, LOW);
  }
  else if (bu2 == 1) {
    digitalWrite(led10, HIGH);
  }
  tone(buzzer1, 200);
  tone(buzzer2, 200);
}
void all(double g) {
  analogWrite(led1, g);
  analogWrite(led2, g);
  analogWrite(led3, g);
  analogWrite(led4, g);
  analogWrite(led5, g);
  analogWrite(led6, g);
  analogWrite(led7, g);
  analogWrite(led8, g);
  analogWrite(led9, g);
  analogWrite(led10, g);
}
void allLEDsOff() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
