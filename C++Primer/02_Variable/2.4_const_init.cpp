#include <iostream>

#include "const.h"

const int gVal = 0;

int get_size()
{
	freopen("data/const_init.txt", "r", stdin);

	int ret;
	std::cin >> ret;

	if (std::cin)
	{
		fclose(stdin);
		return ret;
	}
	else
	{
		std::cout << "Invalid size" << std::endl;
		fclose(stdin);
		return -1;
	}
}

int main()
{
	const int i = get_size();	// runtime initialization
	std::cout << "runtime const: " << i << std::endl;

	int j = 2;
	const int k = j;			// compile time initialization
	std::cout << "compile time const: " << k << std::endl;

	char chr1;					// 0x61feef
	std::cout << static_cast<const void*>(&chr1) << std::endl;
	char str1[i];				// 0x61feb8 dependends on runtime input
	std::cout << static_cast<const void*>(str1) << std::endl;
	char str2[j];				// 0x61fea8 dependends on runtime input
	std::cout << static_cast<const void*>(str2) << std::endl;
	char chr2;					// 0x61feee
	std::cout << static_cast<const void*>(&chr2) << std::endl;

	const int lVal = 0;
	std::cout << static_cast<const void*>(&gVal) << std::endl;	// 0x40606c
	std::cout << static_cast<const void*>(&lVal) << std::endl;	// 0x61fee8

	int *ptr = (int*)&lVal;
	*ptr = -1;
	std::cout << static_cast<const void*>(&lVal) << " -> " << lVal << std::endl;	// 0x61fee8 -> 0
	std::cout << static_cast<const void*>(ptr) << " -> " << *ptr << std::endl;		// 0x61fee8 -> -1

	std::cout << "extern pi: " << pi << std::endl;				// extern variable
	std::cout << "extern const bufSize: " << bufSize << std::endl;	// const extern variable
	std::cout << "const zero: " << zero << std::endl;

	int *nptr = new int;
	std::cout << static_cast<const void*>(nptr) << std::endl;	// 0x7c9fa0

	return 0;
}