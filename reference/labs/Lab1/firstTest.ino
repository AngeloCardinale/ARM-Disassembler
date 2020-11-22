void setup() {
  Serial.begin(9600);     //make sure the reciever is listening at the same speed
  pinMode(13, OUTPUT);
}

void loop() {
 Serial.print("hello there");    //serial ports have 8 bits per byte   one byte per letter plus two for synchronization so ten bits for each letter
                                 //takes about 1ms per letter!!!!!     spend 10ms sending a message and doing nothing 
                                 //100bits/10k bits per second = 1/100 = 10 ms total
 digitalWrite(13,HIGH);
 delay(1000);
 digitalWrite(13,LOW);
 delay(1000);            

}
