#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 7, 5, 4, 3, 2);
Servo myservo;
const int trigPin = 8;
const int echoPin = 9;
const int  buzzerPin = 11;
const int  ledPin = 10;
long duration;
int distance;
int angle;

void setup() {

   lcd.begin(16, 2);
  lcd.print("Radar en balayage");
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  myservo.attach(13);
  delay(1000);
  lcd.clear();

  lcd.begin(16, 2);
  lcd.print("Radar pret");
  delay(1500);
 

}

void loop() {

  for(angle = 0; angle <= 180; angle += 2 ){
    myservo.write(angle);
    delay(30);

    distance = getDistance();

   // lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Angle: ");
    lcd.print(angle);
    lcd.print("   ");

    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm   ");

    if(distance < 15 && distance > 0 ){
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }
    delay(50);
    
    

  }

  for(angle = 180; angle>=0; angle -= 2){
    myservo.write(angle);
    delay(30);

    distance = getDistance();
    lcd.setCursor(0, 0);
    lcd.print("Angle: ");
    lcd.print(angle);
    lcd.print("   ");

    
    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm   ");

     if(distance < 15 && distance > 0 ){
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }
      delay(50);
  }

//digitalWrite(trigPin, LOW);
 //delayMicroseconds(2);
 //delayMicroseconds(10);
 //digitalWrite(trigPin, LOW);

//long duree = pulseIn(echoPin,HIGH);
//int distance = duree * 0.34  / 2;

//Serial.print("distance : ");
//Serial.print(distance);
//Serial.println("cm");


//lcd.setCursor(0, 1);
//lcd.print("                  ");
//lcd.setCursor(0, 1);
//lcd.print("distance: ");
//lcd.print(distance);
//lcd.println(" cm");



//if(distance > 3 && distance < 50 ){
  
  //int intensite = map(distance, 2, 20, 200, 50);
  //analogWrite(ledPin, intensite);

 //int frequence = map(distance, 2, 20, 2000, 500);
//tone(buzzerPin, frequence);
//delay(50);
 //noTone(buzzerPin);
 //delay(50);
//} else{
  //digitalWrite(ledPin, LOW);
  //noTone(buzzerPin);
//}
  //delay(50);
}

int getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.034 / 2;
  
  if(distance > 400) distance = 0;
  return distance;

}

