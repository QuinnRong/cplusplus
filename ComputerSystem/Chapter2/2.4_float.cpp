#include <iostream>
#include <cmath>	/* NAN, INFINITY */

#include "show_bytes.hpp"

#define POS_INFINITY 1e400	/* warning [-Woverflow] */
#define NEG_INFINITY (-POS_INFINITY)
#define POS_ZERO (1.0/POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)

int main()
{
	show_bytes(0.0);	// 00 00 00 00 00 00 00 00
	show_bytes(-0.0);	// 00 00 00 00 00 00 00 80
	show_bytes(+0.0);	// 00 00 00 00 00 00 00 00

	double a = 0.0;
	double b = -0.0;
	if (a == b)
		std::cout << a << " == " << b << std::endl;					// 0 == -0
	else
		std::cout << a << " != " << b << std::endl;

	double c = 1.0;
	double d = c / a;
	std::cout << c << " / " << a << " = " << d << std::endl;		// 1 / 0 = inf
	show_bytes(d);													// 00 00 00 00 00 00 f0 7f

	double e = c / a;
	double f = d - e;
	std::cout << d << " - " << e << " = " << f << std::endl;		// inf - inf = nan
	show_bytes(f);													// 00 00 00 00 00 00 f8 ff
	if (f > 0.0)
		std::cout << "> 0.0" << std::endl;
	else if (f < 0.0)
		std::cout << "< 0.0" << std::endl;
	else if (f == 0.0)
		std::cout << "== 0.0" << std::endl;
	else
		std::cout << "none" << std::endl;							// none

	std::cout << INFINITY << std::endl;	// inf
	show_bytes(INFINITY);				// 00 00 80 7f
	show_bytes(double(INFINITY));		// 00 00 00 00 00 00 f0 7f
	std::cout << NAN << std::endl;		// nan
	show_bytes(NAN);					// 00 00 c0 7f
	show_bytes(double(NAN));			// 00 00 00 00 00 00 f8 7f

	show_bytes(POS_INFINITY);			// 00 00 00 00 00 00 f0 7f
	show_bytes(NEG_INFINITY);			// 00 00 00 00 00 00 f0 ff
	show_bytes(POS_ZERO);				// 00 00 00 00 00 00 00 00
	show_bytes(NEG_ZERO);				// 00 00 00 00 00 00 00 80

	if (POS_INFINITY > 0.0)
		std::cout << POS_INFINITY << " > 0.0" << std::endl;		// inf > 0.0
	if (NEG_INFINITY < 0.0)
		std::cout << NEG_INFINITY << " < 0.0" << std::endl;		// -inf < 0.0
}
