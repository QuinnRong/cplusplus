#include <cstdio>

long long Fibonacci(unsigned int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	long long prev1 = 0, prev2 = 1;
	for (unsigned int i = 0; i < n - 2; ++i)
	{
		long long tmp = prev1 + prev2;
		prev1 = prev2;
		prev2 = tmp;
	}
	return prev1 + prev2;
}

int main()
{
	for (int i = 0; i < 10; ++i)
		printf("%d\n", Fibonacci(i));
}