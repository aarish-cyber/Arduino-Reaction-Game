int rightled = 12;
int green = 11;
int yellow = 10;
int red = 9;
int leftled = 8;

int buzz = 7;

int rightbutt = 13;
int leftbutt = 6;

bool buttonPressed = 0;

int x;
int rightScore = 0;
int leftScore = 0;

  void
  setup() {
  // put your setup code here, to run once:
  pinMode(rightled, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(leftled, OUTPUT);

  pinMode(buzz, OUTPUT);

  pinMode(rightbutt, INPUT_PULLUP);
  pinMode(leftbutt, INPUT_PULLUP);

  randomSeed(analogRead(A0));

  Serial.begin(9600);
}


void loop() {
  // Sound at end
  digitalWrite(green, HIGH);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(920);
  digitalWrite(green, LOW);

  digitalWrite(yellow, HIGH);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(920);
  digitalWrite(yellow, LOW);

  digitalWrite(red, HIGH);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);  // Neeed to randomise
  delay(random(900, 4901));
  digitalWrite(red, LOW);

  while (buttonPressed == 0) {  // FIRST TO PRESS BUTTON
    digitalWrite(rightled, HIGH);
    digitalWrite(leftled, HIGH);

    if (digitalRead(rightbutt) == 0) {
      buttonPressed = 1;
      digitalWrite(leftled, LOW);
      rightScore++;
      Serial.print("Right Player Wins! Score - Right: ");
      Serial.print(rightScore);
      Serial.print(" | Left: ");
      Serial.println(leftScore);
    } else if (digitalRead(leftbutt) == 0) {
      buttonPressed = 1;
      digitalWrite(rightled, LOW);
      leftScore++;
      Serial.print("Left Player Wins! Score - Right: ");
      Serial.print(rightScore);
      Serial.print(" | Left: ");
      Serial.println(leftScore);
    }
  }
  for (x = 0; x < 7; x++)  // Winner Tune
  {
    digitalWrite(buzz, HIGH);
    delay(50);
    digitalWrite(buzz, LOW);
    delay(50);
  }

  if (rightScore >= 5)
  {
    Serial.println("RIGHT WINS !!!!");
    rightScore =0;
    leftScore =0;
    Serial.println("NEW GAME");
  }
  else if (leftScore >= 5)
  {
    Serial.println("LEFT WINS !!!!");
     rightScore =0;
    leftScore =0;
     Serial.println("NEW GAME");
  }



  delay(5000);  /// Restarting Game
  digitalWrite(rightled, LOW);
  digitalWrite(leftled, LOW);
  buttonPressed = 0;
}
