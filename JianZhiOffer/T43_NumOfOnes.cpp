#include <cstdio>

int PowerBaseTen(int n)
{
	int res = 1;
	for (int i = 0; i < n; ++i)
		res *= 10;
	return res;
}

int NumOfOnes(int N)
{
	int temp = N;
	int num[100];
	int index = -1;
	while (temp > 0)
	{
		++index;
		num[index] = temp % 10;
		temp /= 10;
	}
	temp = N;
	int res = 0;
	for (int i = index; i >= 0; --i)
	{
		if (num[i] == 1)
		{
			res += i * PowerBaseTen(i - 1);
			temp -= num[i] * PowerBaseTen(i);
			res += 1 + temp;
		}
		if (num[i] > 1)
		{
			res += num[i] * i * PowerBaseTen(i - 1);
			res += PowerBaseTen(i);
			temp -= num[i] * PowerBaseTen(i);
		}
	}
	return res;
}

int TestCore(int n)
{
	int res = 0;
	while (n > 0)
	{
		if ((n % 10) == 1) res += 1;
		n /= 10;
	}
	return res;
}

int Test(int N)
{
	int res = 0;
	for (int i = 0; i <= N; ++i)
		res += TestCore(i);
	return res;
}

int main()
{
	for (int i = 0; i < 2000; ++i)
	{
		int a = NumOfOnes(i), b = Test(i);
		if (a != b)
			printf("%d: %d %d\n",i, a, b);
	}
	printf("%d\n", NumOfOnes(21345));
}