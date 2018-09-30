#include <cstdio>

int maxProductAfterCutting(int length)
{
	if (length < 2) return 0;
	if (length == 2) return 1;
	if (length == 3) return 2;

	int* products = new int[length + 1];

	for (int i = 0; i <= length; ++i)
	{
		int max = i;
		for (int j = 1; j < i; ++j)
		{
			int product = products[j] * (i - j);
			// printf("%d %d %d\n", j, i - j, product);
			if (product > max) max = product;
		}
		products[i] = max;
	}

	int res = products[length];
	delete[] products;
	return res;
}

int main()
{
	for (int i = 0; i < 10; ++i)
		printf("%d -> %d\n", i, maxProductAfterCutting(i));
}