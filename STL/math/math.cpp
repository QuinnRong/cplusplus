#include <cmath>
#include <cstdio>
#include <cstdlib>

/****
@<cmath>
pow:
    double pow (double base, double exponent);
exp:
    double exp (double x);
log:
    double log (double x);
log10:
    double log10 (double x);
log2:
    double log2  (double x);
sqrt:
    double sqrt (double x);
abs:
         double abs (     double x);
          float abs (      float x);
    long double abs (long double x);
         double abs (          T x);           // additional overloads for integral types

@<cstdlib>
abs:
              int abs (          int n);
         long int abs (     long int n);
    long long int abs (long long int n);
****/

int main()
{
    int base = 2, exponent = 3;
    printf("%d^%d = %d\n", base, exponent, (int)pow(base,exponent));

    int p = 3;
    printf("e^%d = %f\n", p, exp(p));

    int x = 10;
    printf("log(%d) = %f\n", x, log(x));
    printf("log2(%d) = %f\n", x, log2(x));
    printf("log10(%d) = %f\n", x, log10(x));

    int s = 10;
    printf("sqrt(%d) = %f\n", s, sqrt(s));
}

/*
results:
2^3 = 8
e^3 = 20.085537
log(10) = 2.302585
log2(10) = 3.321928
log10(10) = 1.000000
sqrt(10) = 3.162278
*/