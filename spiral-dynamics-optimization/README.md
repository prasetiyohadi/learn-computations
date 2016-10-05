# Spiral Dynamics Optimization

## Spiral Dynamics

Paper: Tamura, K. and Yasuda, K., Spiral Dynamics Inspired Optimization

**Algorithm**

* step 0: preparation
* number of search points: m >= 2
* parameters of S2(r, tetha): 0 <= tetha < 2pi, 0 < r < 1
* maximum iteration numbers: k_max
* step 1: initialization
  * initial points: x_i(0) elements of R2, i = 1, 2, ..., m
  * center x* = x_{ig}(0), ig = arg min f(x_i(0)), i = 1, 2, ..., m
* step 2: updating x_i
  * x_i(k+1) = S2(r, tetha)x_i(k) - S2(r, tetha - I2)x*, i = 1, 2, ..., m
* step 3: updating x*
  * x* = x_{ig}(k+1), ig = arg min f(x_i(k+1)), i = 1, 2, ..., m
* step 4: checking terminating criterion
  * if k = k_max, then terminate
  * otherwise, set k = k + 1, return to step 2

**Compilation Procedure (GCC 6)**

```
$ g++ spiralOptimization2d.cpp sobol.o -I ./
```

if compilation failed due to different C++ standard use C++11 standard flag

```
$ g++ spiralOptimization2d.cpp sobol.o -I ./ -std=gnu++11
```

Output: **a.out**

**Execution Procedure**

```
$ ./a.out > spiralOptimization2d.dat
$ ./spiralOptimization2d.plot
```

Output: **spiralOptimization2d.eps**

## Sobol Sequence

Sobol sequences are an example of quasi-random low-discrepancy sequences.

[C++ Library](https://people.sc.fsu.edu/~jburkardt/cpp_src/sobol/sobol.html)

**Compilation Procedure (GCC 6)**

```
$ g++ -c sobol.cpp -I ./
```

Output: **sobol.o**
