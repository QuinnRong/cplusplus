#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <functional>   /* bind */

/*****
@cstdlib
rand:
    int rand (void);
    Returns a pseudo-random integral number in the range between 0 and RAND_MAX.

srand:
    void srand (unsigned int seed);
    The pseudo-random number generator is initialized using the argument passed as seed.

RAND_MAX:
    This value is library-dependent, but is guaranteed to be at least 32767 on any standard library implementation.

@ctime
time:
    time_t time (time_t* timer);
    Get the current calendar time as a value of type time_t.
    The function returns this value, and if the argument is not a null pointer,
    it also sets this value to the object pointed by timer.

time_t:
    For historical reasons, it is generally implemented as an integral value
    representing the number of seconds elapsed since 00:00 hours, Jan 1, 1970 UTC (i.e., a unix timestamp).
    Although libraries may implement this type using alternative time representations.

@random
This header introduces random number generation facilities.
This library allows to produce random numbers using combinations of generators and distributions:
    Generators: Objects that generate uniformly distributed numbers.
    Distributions: Objects that transform sequences of numbers generated by a generator into sequences of numbers
                    that follow a specific random variable distribution, such as uniform, Normal or Binomial.
*****/

double rand_range(double r1, double r2)
{
    double tmp = rand() * 1.0 / RAND_MAX;
    return r1 + tmp * (r2 -r1);
}

int rand_range(int r1, int r2)
{
    return r1 + rand() % (r2 -r1 + 1);
}

int main ()
{
    printf("RAND_MAX = %d\n", RAND_MAX);            // 32767

    printf ("First number: %d\n", rand()%100);      // First number: 41
    srand (time(NULL));
    printf ("Random number: %d\n", rand()%100);     // Random number: 74
    srand (1);
    printf ("Again the first number: %d\n", rand()%100);    // Again the first number: 41

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,6);
    printf("dice_roll =");
    for (int i = 0; i < 6; ++i)
    {
        int dice_roll = distribution(generator);    // generates number in the range 1..6 
        printf(" %d", dice_roll);                   // dice_roll = 1 1 5 3 4 2
    }
    printf("\n");

    auto dice = std::bind ( distribution, generator );
    printf("wisdom =");
    for (int i = 0; i < 6; ++i)
    {
        int wisdom = dice()+dice()+dice();
        printf(" %d", wisdom);                      // wisdom = 11 13 7 10 7 15
    }
    printf("\n");
    return 0;
}