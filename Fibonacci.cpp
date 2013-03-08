#include <iostream>
using namespace std;

/*
 * Different ways to compute the f(n)
 */


// An exponential algorithm -- can only compute F200
int fib1(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib1(n - 1) + fib1(n - 2);
}

// An polinomial algorithm -- can only compute 200000
int fib2(int n) {
    if (n == 0) {
        return 0;
    }
    int *f = new int[n];
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// Even better -- to use the matrix.
//      [0 1]
//      [1 1]
// And use the efficient exponentiation to compute the matrix Muliplication.

int fib3(int n) {

    struct Multiplier {
        int a1, a2;
    }M2;

    struct Matrix {
        int b1, b2;
        int b3, b4;
    }M1;

    return 0;
}

/* Efficient Exponentiation
 *
long long pow(int x, int n) {

    if (n == 0) 
        return 1;
    if (n == 1) 
        return x;

    if (n % 2 == 0) 
        return pow(x * x, n / 2);
    else    return pow(x * x, n / 2) * x;
}

*/
int main()
{
    
    cout << fib2(10000) << endl;

    return 0;
}


