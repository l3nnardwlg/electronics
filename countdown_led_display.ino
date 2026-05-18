const int buttonPin = 2;

int segA = 3;
int segB = 4;
int segC = 5;
int segD = 6;
int segE = 7;
int segF = 8;
int segG = 9;

int redLed = 10;
int yellowLed = 11;
int greenLed = 12;

int segments[] = {
  segA, segB, segC,
  segD, segE, segF, segG
};

byte numbers[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);

  for(int i=0; i<7; i++) {
    pinMode(segments[i], OUTPUT);
  }

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  clearDisplay();
}
  void clearLEDs() {

  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}


void loop() {

  if(digitalRead(buttonPin) == LOW) {

    countdown();

    delay(500);
  }
}

void showNumber(int number) {

  for(int i=0; i<7; i++) {

    digitalWrite(
      segments[i],
      numbers[number][i]
    );
  }
}

void clearDisplay() {

  for(int i=0; i<7; i++) {

    digitalWrite(
      segments[i],
      LOW
    );
  }
}

void countdown() {

  clearLEDs();

  showNumber(5);
  delay(1000);

  showNumber(4);
  delay(1000);

  
  showNumber(3);

  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);

  delay(1000);

  
  showNumber(2);

  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(greenLed, LOW);

  delay(1000);

  
  showNumber(1);

  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);

  delay(1000);

  clearDisplay();
  clearLEDs();
}