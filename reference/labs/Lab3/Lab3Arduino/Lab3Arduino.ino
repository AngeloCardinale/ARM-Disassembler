void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float powerRatio = 9;
  float timeConstant = 10.0-powerRatio; 

  //if power ratio is 5 we want it off for 5ms on for 5ms
  //if power ratio is 7 we want it off for 3ms and on for 7ms
  //10-powerRatio off powerRatio on
  while(1){
  digitalWrite(10, HIGH);
  delay(powerRatio);
  digitalWrite(10, LOW);
  delay(timeConstant);
  }
  
}
