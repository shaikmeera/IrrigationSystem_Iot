const int trigP = 2;  //D4 Or GPIO-2 of nodemcu
const int echoP = 0;  //D3 Or GPIO-0 of nodemcu

void setup() {
pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
pinMode(echoP, INPUT);   // Sets the echoPin as an Input
Serial.begin(115200);      // Open serial channel at 9600 baud rate
Serial.println("Boot Up...");
}

void loop() {

  long duration, inches, cm;
  digitalWrite(trigP, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay 
  
  digitalWrite(trigP, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trigP, LOW);   // trigPin low
  
//duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
//distance= duration*0.034/2;        //Calculating actual/real distance
//
//Serial.print("Distance = ");        //Output distance on arduino serial monitor 
//Serial.println(distance);
//delay(3000);                        //Pause for 3 seconds and start measuring distance again

   duration = pulseIn(echoP, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(1000);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
