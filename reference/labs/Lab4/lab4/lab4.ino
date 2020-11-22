/*
 * Michael DiGregorio
 * I pledge my honor I have abided by the stevens honor system
 * Michael DiGregorio, Angelo Cardinale
 * Angelo helped greatly
 */

void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(A7, INPUT);

Serial.begin(9600);
analogReadResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:

while(analogRead(A7)<3783){

  Serial.print(('\n'));
  Serial.print(analogRead(A7));
}
Serial.print("Done 1");
long t0 = micros();

while(analogRead(A0)>3783){

  Serial.print(('\n'));
  Serial.print(analogRead(A0));
}
Serial.print("Done 2");
long t1 = micros();

if(t1 > t0){
uint64_t long timeElapsed = t1-t0;
Serial.print(('\n'));
Serial.print(analogRead(timeElapsed));
delay(2000);
  
}
else{

  Serial.print(analogRead('\n'));
  Serial.print(("Error"));
  delay(2000);
}
}
