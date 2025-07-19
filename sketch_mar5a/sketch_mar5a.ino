#include <Servo.h>
#include <Ultrasonic.h>

Ultrasonic u = Ultrasonic(3,2);  // 3 >> Trig , 2 >> Echo
Servo s = Servo();

void setup() {

  //Right Motor Pins
  pinMode(11, OUTPUT);   // Speed of Right Motor
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  analogWrite(11, 150);  // 0 - 255 

  //Left Motor Pins
  pinMode(5, OUTPUT);    // Speed of Left Motor
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  analogWrite(5, 175);    // 0 - 255

  Serial.begin(9600);

  s.attach(6);
  s.write(90); // Set Servo to 90
  delay(500);
}

void loop() {
 
 int x = Serial.read();

 int d = u.read();  //Distance read and store
 Serial.println(d);
 delay(300);

 if(d<40){
  //Stop
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(4, LOW);
      digitalWrite(8, LOW);
      delay(300);

  //Servo Look Left
      s.write(45);
      delay(500);
      int dl = u.read();  // Update the Left Distance
      delay(100);

      s.write(90);
      delay(500);

  //Servo Look Right
      s.write(135);
      delay(500);
      int dr = u.read();  // Update the Right Distance
      delay(100);

  if(dr>d){
      s.write(90);
      delay(100);

      //Turn Right
       digitalWrite(13, LOW);
       digitalWrite(12, HIGH);
       digitalWrite(4, HIGH);
       digitalWrite(8, LOW);
       delay(300);

       //Stop
       digitalWrite(13, LOW);
       digitalWrite(12, LOW);
       digitalWrite(4, LOW);
       digitalWrite(8, LOW);
       delay(300);

  }
else{
       //  Turn Left
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(4, LOW);
        digitalWrite(8, HIGH);
        delay(300);

      // Stop
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(4, LOW);
        digitalWrite(8, LOW);
        delay(300);

        s.write(90);
        delay(500);
  }

 }

 if(x == '1'){
 //Forword
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  delay(1000);

 }

 if(x == '2'){
 //Backword
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  delay(1000);

}

if(x == '3'){
 // Turn Left
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(4, LOW);
  digitalWrite(8, LOW);
 
}

if(x == '4'){
 // Turn Right
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  delay(500);

  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(4, LOW);
  digitalWrite(8, LOW);
 
}

if(x == '5'){
  //Stop
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(4, LOW);
  digitalWrite(8, LOW);
  delay(1000);
}

}