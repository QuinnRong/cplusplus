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
 * result:
 * fun(0) -> 3.14
 * fun(1) -> 3.14
 * fun(2) -> 3.139999866485596
 * fun(3) -> 2.000000610351563
 * Segmentation fault
 */