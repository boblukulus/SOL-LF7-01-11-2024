//LEDs AutoAmpel
int redledpin = 13;
int yellowledpin = 12;
int greenledpin = 11;
//LEDs Fußgängerampel
int requestledpin = 4;
int stopledpin = 3;
int goledpin = 2;
//Knopf
int button = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(redledpin, OUTPUT);
  pinMode(yellowledpin, OUTPUT);
  pinMode(greenledpin, OUTPUT);
  pinMode(requestledpin, OUTPUT);
  pinMode(stopledpin, OUTPUT);
  pinMode(goledpin, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (digitalRead(button) == HIGH) {
    //Anfrage anzeigen
    digitalWrite(requestledpin, HIGH);
    delay(5000);
    //Fahrzeugampel blinken lassen um den Wechsel anzuzeigen
    digitalWrite(greenledpin, LOW);
    delay(500);
    digitalWrite(greenledpin, HIGH);
    delay(500);
    digitalWrite(greenledpin, LOW);
    delay(500);
    digitalWrite(greenledpin, HIGH);
    delay(500);
    digitalWrite(greenledpin, LOW);
    delay(500);
    digitalWrite(greenledpin, HIGH);
    delay(500);
    digitalWrite(greenledpin, LOW);
    //Fahrzeugampel zu rot schalten
    digitalWrite(yellowledpin, HIGH);
    delay(3000);
    digitalWrite(redledpin, HIGH);
    digitalWrite(yellowledpin, LOW);
    //Fußgängerampel freigeben
    delay(5000);
    digitalWrite(requestledpin, LOW);
    digitalWrite(goledpin, HIGH);
    digitalWrite(stopledpin, LOW);
    delay(10000);
    //Fußgänger stoppen und warnen
    digitalWrite(goledpin, LOW);
    delay(500);
    digitalWrite(goledpin, HIGH);
    delay(500);
    digitalWrite(goledpin, LOW);
    delay(500);
    digitalWrite(goledpin, HIGH);
    delay(500);
    digitalWrite(stopledpin, HIGH);
    digitalWrite(goledpin, LOW);
    //Fahrzeuge freigeben
    delay(3000);
    digitalWrite(redledpin, HIGH);
    digitalWrite(yellowledpin, HIGH);
    delay(1500);
  } else {
    digitalWrite(greenledpin, HIGH);
    digitalWrite(redledpin, LOW);
    digitalWrite(yellowledpin, LOW);
    digitalWrite(requestledpin, LOW);
    digitalWrite(goledpin, LOW);
    digitalWrite(stopledpin, HIGH);
  }
}
