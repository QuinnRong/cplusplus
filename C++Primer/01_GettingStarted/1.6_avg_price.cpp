#include <iostream>
#include <cstdio>

#include "Sales_item.h"

int main()
{
	freopen("data/book_sales.txt", "r", stdin);

	Sales_item total, trans;

	if (std::cin >> total)
	{
		while (std::cin >> trans)
		{
			if (total.isbn() == trans.isbn())
				total += trans;
			else
			{
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

	fclose(stdin);
	return 0;
}