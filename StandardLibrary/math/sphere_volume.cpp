#include <cmath>
#include <cstdio>

using namespace std;

double volume(int dim, double rad)
{
    double gamma = exp(lgamma(1 + dim / 2.0));
    double pi = pow(M_PI, dim / 2.0);
    return (pi / gamma * pow(rad, dim));
}

double radius(int dim, double vol)
{
	double gamma = exp(lgamma(1 + dim / 2.0));
    double pi = pow(M_PI, dim / 2.0);
    return pow(vol * gamma / pi, 1.0 / dim);
}

int main()
{
	double rad = 1;
	for (int dim = 0; dim < 5; ++dim)
	{
		printf("volume(%d, %f) = %f\n", dim, rad, volume(dim, rad));
	}

	double vol = 1;
	for (int dim = 0; dim < 5; ++dim)
	{
		printf("radius(%d, %f) = %f\n", dim, vol, radius(dim, vol));
	}

	int dim = 3;
	vol = 0.7 / 1000;
	printf("radius(%d, %f) = %f\n", dim, vol, radius(dim, vol));
}
