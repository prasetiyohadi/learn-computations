// Name: Prasetiyo Hadi Purwoko
// NIM: 20915301
// Primality test
// Miller-Rabin probability test
// Using GMP library for big number operation
// compile like this: g++ millerrabin.cpp -o millerrabin -lgmpxx -lgmp

#include <iostream>
#include <cstdlib>
#include <gmpxx.h>

using namespace std;
int main () {
  bool prime = true, loop = true, check;
  int i, j, k, s;
  mpz_class d, n, r, x;
  cout << "input a number: " << endl;
  cin >> n;
  if (n < 2) {
    cout << "number must be greater than 2" << endl;
    return 1;
  }
  if (n == 2 || n == 3) {
    cout << "it is a prime number" << endl;
    return 1;
  }
  if (n % 2 == 0) {
    cout << "it is an even number" << endl;
    return 1;
  }
  d = n - 1;
  s = 0;
  while (d%2 == 0) {
    d = d / 2;
    ++s;
  }
  //cout << "value of d: " << d << endl;
  //cout << "value of s: " << s << endl;
  k = 10;
  for(i=0; loop && i<k; i++) {
    check = false;
    r = rand() % (n-2) + 2;
    //cout << "random number: " << r << endl;
    mpz_powm(x.get_mpz_t(), r.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
    //cout << "outer x: " << x << endl;
    if (x == 1 || x == n-1) check = true;
    //cout << "inner x: ";
    for(j=0; !check && j<s-1; j++) {
      mpz_powm_ui(x.get_mpz_t(), x.get_mpz_t(), 2, n.get_mpz_t());
      //cout << x << " ";
      if (x == 1) prime = false;
      if (x == n-1) check = true;
    }
    //cout << endl;
    if (!check && prime) {
      prime = false;
      loop = false;
    }
  }
  if (!prime) {
    cout << "it is a composite number" << endl;
  } else {
    cout << "it is probably a prime number" << endl;
  }
  return 0;
}
