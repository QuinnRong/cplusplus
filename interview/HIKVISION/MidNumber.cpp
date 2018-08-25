#include <iostream>

using namespace std;

#define MaxOfThree(a,b,c) ((a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c)))
#define MidOfThree(a,b,c) ((a)>(b)?((b)>(c)?(b):((a)>(c)?(c):(a))):\
                                   ((a)>(c)?(a):((b)>(c)?(c):(b))))
#define MinOfThree(a,b,c) ((a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c)))

int main()
{
    cout << MaxOfThree(2,3,1) << endl;
    cout << MidOfThree(2,3,1) << endl;
    cout << MinOfThree(2,3,1) << endl;
}