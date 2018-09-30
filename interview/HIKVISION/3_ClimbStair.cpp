#include <cstdio>

int ClimbStair(int n)
{
	if (n <= 1) return 1;
	int prev1 = 1, prev2 = 1, res;
	for (int i = 1; i < n; ++i)
	{
		res = prev1 + prev2;
		prev1 = prev2;
		prev2 = res;
	}
	return res;
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		int res = ClimbStair(i);
		printf("%d -> %d\n", i, res);
	}
}