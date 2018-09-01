#include <cstdio>

bool g_InvalidInput = false;

double PowerOfUnsigned(double base, unsigned exponent)
{
	double res = 1.0;
	for (unsigned i = 0; i < exponent; ++i) res *= base;
	return res;
}

double PowerOfUnsignedNew(double base, unsigned exponent)
{
	if (exponent == 0) return 0;
	if (exponent == 1) return base;
	double res = PowerOfUnsignedNew(base, exponent >> 1);
	res *= res;
	if (exponent & 1 == 1) res *= base;
	return res;
}

bool equal(double x, double y)
{
	double MIN = 0.0000001;
	if (x - y < MIN && x - y > -MIN) return true;
	else return false;
}

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base, 0.0) && equal(exponent, 0))
	{
		g_InvalidInput = true;
		return 0.0;
	}
	if (exponent >= 0) return PowerOfUnsignedNew(base, exponent);
	else return 1.0 / PowerOfUnsignedNew(base, -exponent);
}

int main()
{
	printf("%f\n", Power(2, 3));
	printf("%f\n", Power(2, -3));
}