#include <iostream>

int main()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;	// 32
	std::cout << u - u2 << std::endl;	// 2^32 - 32

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;	// 32
	std::cout << i - i2 << std::endl;	// -32
	std::cout << i - u << std::endl;	// 0
	std::cout << u - i << std::endl;	// 0

	i = -10;
	if (i > u)							// true, prints -10 > 10
	{
		std::cout << i << " > " << u << std::endl;
	}
	else
	{
		std::cout << i << " < " << u << std::endl;
	}

	i = -1;
	u = 1;
	std::cout << i * u << std::endl;	// 2^32 - 1 = 4294967295

	return 0;
}