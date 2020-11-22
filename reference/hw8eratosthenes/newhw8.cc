#include<iostream>
#include<cmath>
using namespace std;



extern uint32_t eratosthenes(uint32_t* array, uint32_t n, uint32_t m);

int main(int argc, char**argv){
  if (argc != 2) return -1;
  uint32_t n = atoi(argv[1]);
  uint32_t* sieve = new uint32_t[(n+31)/32];
  uint32_t m;
  m = sqrt(n);
  uint32_t count = eratosthenes(sieve, n, m);
  cout<< "Primes up to "<<n<<" = "<<count<<'\n';
  delete [] sieve;
  return 0;


}
