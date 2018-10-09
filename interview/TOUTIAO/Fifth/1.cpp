#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool beautiful(int a, int b, int k)
{
	int remain;
	while (k > 0)
	{
		remain = k % 10;
		if (remain != a && remain != b) return false;
		k /= 10;
	}
	return true;
}

int Combination(int m, int n)
{
	if (n * 2 > m) n = m - n;

	long long res = 1;
	for (int i = 1; i <= n; ++i)
	{
		res *= m;
		res /= i;
		if (res >= 1000000007) res %= 1000000007;
		--m;
	}
	return res;
}

int main()
{
	freopen("1.txt", "r", stdin);
	int a, b, k;
	cin >> a >> b >> k;

	long long res = 0;

	for (int i = 0; i <= k; ++i)
	{
		if (beautiful(a, b, i * a + (k - i) * b))
		{
			res += Combination(k, i);
			if (res >= 1000000007) res %= 1000000007;
		}
	}

	printf("%d\n", res);

	fclose(stdin);
	return 0;
}