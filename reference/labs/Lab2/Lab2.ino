
#include <cmath>

double place[10]={0};
double wait = (1.0/440.0) / (double)10*1000000.0 / 1.0;

void setup(){
pinMode(DAC1, OUTPUT);
analogWriteResolution(12);
for(int i = 0; i < 10; ++i){
  place[i] = sin((float)i/(double)10*2*3.14159265)*2047 + 2047;
}
}

void loop() {
for(int i = 0; i< 10; i++){
  analogWrite(DAC1, place[i]);
  delayMicroseconds(wait);
}

  
}
