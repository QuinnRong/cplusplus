#include <iostream>
#include <cstdio>

#include "Sales_item.h"

int main()
{
	freopen("data/item_add.txt", "r", stdin);
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	fclose(stdin);

	if (item1.isbn() == item2.isbn())
	{
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "Data must refer to same ISBN" << std::endl;
		return -1;
	}
}