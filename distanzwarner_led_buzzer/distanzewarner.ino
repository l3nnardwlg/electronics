#define TRIG 9
#define ECHO 10

#define GREEN_LED 3
#define RED_LED 4
#define BUZZER 5

void setup() {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);

  int distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (distance < 20) {

    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    int ton = map(distance, 1, 20, 2000, 300);

    tone(BUZZER, ton);

  } else {

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    noTone(BUZZER);
  }

  delay(50);
}
