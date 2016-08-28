# Miller-Rabin primality test

The Miller–Rabin primality test or Rabin–Miller primality test is a primality test: an algorithm which determines whether a given number is prime or not. The algorithm, as modified by Michael O. Rabin to avoid the generalized Riemann hypothesis, is a probabilistic algorithm. (From [Wikipedia](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test))

* The nature of the test involves big numbers, so the use of "big numbers" libraries (or similar features of the language of your choice) are suggested, but not mandatory.
* Deterministic variants of the test exist and can be implemented as extra (not mandatory to complete the task

File millerrabin.cpp contain C++ code which uses GMP (GNU Multiple-precision) library for big number operation. You can compile using the following command

```
$ g++ millerrabin.cpp -lgmpxx -lgmp
```

Then you can try to execute the program

```
$ ./a.out
input a number: 
623867
it is probably a prime number
$ ./a.out
input a number: 
623871
it is a composite number
```

