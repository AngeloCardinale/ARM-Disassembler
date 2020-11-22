#include <iostream>
#include<cmath>
using namespace std;
/*
	Write an assembler subroutine to calculate eratosthenes' sieve.
	You are counting the number of primes from 2 to n.
	First set all bits to 1 (you can do this 32 bits at a time by setting
	each word to 0xFFFFFFFF)
	Then for each prime (for example 2) clear all multiples of that number.
	pseudocode:

	set all numbers to prime
	for i = 4 to n step 2
	  isPrime[i] = false   (4, 6, 8, ... not prime)

	for i = 3 to n step 2
	  if isPrime(i)
      for j = i*i to n step 2*i
        isPrime[j] = false

 */

<<<<<<< HEAD
//extern uint32_t eratosthenes(uint32_t* array, uint32_t n);
extern uint32_t display(int n);
=======
extern uint32_t eratosthenes(uint32_t* array, uint32_t n, uint32_t m);
>>>>>>> 93e681afb51153a647c6ad3045fbfee34e24dd5c

/*
int main() {
<<<<<<< HEAD
	uint32_t n = 1000.000.000;
=======
	uint32_t n = 1000;
>>>>>>> 93e681afb51153a647c6ad3045fbfee34e24dd5c
	uint32_t* sieve = new uint32_t[(n+31)/32];
	uint32_t m;
	m = sqrt(n);
	uint32_t count = eratosthenes(sieve, n, m);
	cout << "Primes up to " << n << " = " << count << '\n';
	delete [] sieve;
}
*/
int main(){
  int n = 5;
  cout<<display(n)<<endl;
  return 0;

}
