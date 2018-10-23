#include <iostream>
#include <cstdio>

int main()
{
	freopen("data/occurs.txt", "r", stdin);

	int currVal, val;
	if (std::cin >> currVal)
	{
		int cnt = 1;
		while (std::cin >> val)
		{
			if (val == currVal)
				++cnt;
			else
			{
				std::cout << currVal << " occurs "
						  << cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs "
				  << cnt << " times" << std::endl;
	}

	fclose(stdin);
	return 0;
}