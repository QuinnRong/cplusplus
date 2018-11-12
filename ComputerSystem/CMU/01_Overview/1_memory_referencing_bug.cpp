#include <iostream>
#include <iomanip>

using namespace std;

struct struct_t
{
	int a[2];
	double d;
};

double fun(int i)
{
	struct_t s;
	s.d = 3.14;
	s.a[i] = 1073741824;
	return s.d;
}

int main()
{
	for (int i = 0; i < 6; ++i)
		cout << "fun(" << i << ") -> " << setprecision(16) << fun(i) << endl;
	return 0;
}

/**
 * memory
 * 3: d_hi
 * 2: d_lo
 * 1: a[1]
 * 0: a[0]
 * 
 * 1073741824:
 * 0x40000000
 * 
 * result:
 * fun(0) -> 3.14
 * fun(1) -> 3.14
 * fun(2) -> 3.139999866485596
 * fun(3) -> 2.000000610351563:   0100 0...0 -> 2^(2^11 - (2^11 - 1))*1.0 = 2.0
 * Segmentation fault
 */