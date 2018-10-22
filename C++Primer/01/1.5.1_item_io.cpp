#include <iostream>
#include <cstdio>

#include "Sales_item.h"

int main()
{
	freopen("data/item_io.txt", "r", stdin);

	Sales_item book;
	std::cin >> book;
	std::cout << book << std::endl;

	fclose(stdin);
	return 0;
}