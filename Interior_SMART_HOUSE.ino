#include <DHT.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PLUIE A0
#define FLAMME A1
#define FUMEE A2
#define SON 2
#define DHTPIN 4
#define BUZZER 5
#define LED_ROUGE 6
#define LED_BLANCHE 7
#define SERVO_INT 10

DHT dht(DHTPIN, DHT11);
Servo servoInterieur;
LiquidCrystal_I2C lcd(0x27, 16, 2);

bool etatSon = false;
bool lingrabat = false;
bool flammeencours = false;
bool alertactive = false;

void setup() {
  Serial.brgin(9600);
  pinMode(PLUIE, INPUT);
  pinMode(FLAMME, INPUT);
  pinMode(FUMEE, INPUT);
  pinMode(SON, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_BLANCHE, OUTPUT);

  servoInterieur.attach(SERVO_INT);
  servoInterieur.write(0);
  dht.begin();
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  int pluie = analogRead(PLUIE);
  int flamme = analogRead(FLAMME);
  int fumee = analogRead(FUMEE);
  int son = digitalRead(SON);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Pluie
  if (pluie < 500 && !lingerabat){ 
    servoInterieur.write(180); 
    lingerabat = true;
  } else if (pluie > 600 && lingerabat){
    servoInterieur.write(0);
    lingerabat = false;
  }
  // Flamme
  if (flamme < 500 && !flammeencours){ tone(BUZZER, 1000); flammeencours=true;}
  else if (flamme >= 500 && flammeencours) {noTone(BUZZER); flammeencours=false;}

  // Fumée
  if (fumee > 300) digitalWrite(LED_ROUGE, HIGH);
  else digitalWrite(LED_ROUGE, LOW);

  // Son
  if (son == HIGH) {
    etatSon = !etatSon;
    digitalWrite(LED_BLANCHE, etatSon);
    delay(100);
  }

  // Affichage LCD
  lcd.clear();
  if (flamme < 500) {
    lcd.print("ALERTE FEU!");
  } else if (fumee > 300) {
    lcd.print("ALERTE FUMEE!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(t);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("H:");
    lcd.print(h);
    lcd.print("%");
  }

  delay(500);
}
