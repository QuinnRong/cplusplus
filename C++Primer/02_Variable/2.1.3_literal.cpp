#include <iostream>

int main()
{
	std::cout << 0x00000000 << std::endl;	// 0
	std::cout << 0x7fffffff << std::endl;	// 2^31 - 1 = 2147483647
	std::cout << 0x80000000 << std::endl;	// 2^31 = 2147483648
	std::cout << 0xffffffff << std::endl;	// 2^32 - 1 = 4294967295

	int x;
	x = 0x00000000; std::cout << x << std::endl;	// 0
	x = 0x7fffffff; std::cout << x << std::endl;	// 2^31 - 1 = 2147483647
	x = 0x80000000; std::cout << x << std::endl;	// -2^31 = -2147483648
	x = 0xffffffff; std::cout << x << std::endl;	// -1

	return 0;
}
