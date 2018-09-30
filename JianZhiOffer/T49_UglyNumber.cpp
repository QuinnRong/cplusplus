#include <cstdio>

int GetUglyNumber(int index)
{
	if (index <= 0) return -1;

	int *res = new int[index];

	int pow2 = 0, pow3 = 0, pow5 = 0;
	res[0] = 1;
	for (int i = 1; i < index; ++i)
	{
		if (res[pow2] * 2 > res[pow3] * 3)
		{
			if (res[pow3] * 3 > res[pow5] * 5)
			{
				res[i] = res[pow5] * 5;
				++pow5;
			}
			else if (res[pow3] * 3 < res[pow5] * 5)
			{
				res[i] = res[pow3] * 3;
				++pow3;
			}
			else
			{
				res[i] = res[pow3] * 3;
				++pow3;
				++pow5;
			}
		}
		else if (res[pow2] * 2 < res[pow3] * 3)
		{
			if (res[pow2] * 2 > res[pow5] * 5)
			{
				res[i] = res[pow5] * 5;
				++pow5;
			}
			else if (res[pow2] * 2 < res[pow5] * 5)
			{
				res[i] = res[pow2] * 2;
				++pow2;
			}
			else
			{
				res[i] = res[pow2] * 2;
				++pow2;
				++pow5;
			}
		}
		else
		{
			if (res[pow2] * 2 > res[pow5] * 5)
			{
				res[i] = res[pow5] * 5;
				++pow5;
			}
			else if (res[pow2] * 2 < res[pow5] * 5)
			{
				res[i] = res[pow2] * 2;
				++pow2;
				++pow3;
			}
			else
			{
				res[i] = res[pow2] * 2;
				++pow2;
				++pow3;
				++pow5;
			}
		}
	}
	int ugly = res[index - 1];
	delete[] res;
	return ugly;
}

int main()
{
	for (int i = 1; i < 1000; ++i)
		printf("%d\n", GetUglyNumber(i));

	printf("%d\n", GetUglyNumber(1500));
}