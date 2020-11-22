/*
Michael DiGregorio 
I pledge my honor that I have abided by the Stevens Honor System 


*/

#include<iostream>
using namespace std;


// sum the numbers from 1 to n and return the answer
int sum(int n) {
int sV = 0;
for (int i=n; i>=1;i--){
sV+=i;
}
return sV;
}

// sum the numbers from 1/1 to 1/n and return
float sumReciprocals(int n) {

float sR = 0;
for(float i = 1; i <=n; i++){
sR += (1/i);

}
return sR;
}

// sum the numbers from 1/n to 1/1 (same as above but reversed) and return
float sumReciprocalsReverse(int n) {
float sRR = 0;
for (float i=n;i>=1;i--){
sRR += (1/i);

}
return sRR;
}

int main() {
	cout << sum(100) << '\n';
	cout << sumReciprocals(100) << '\n';
	cout << sumReciprocalsReverse(100) << '\n';
}
