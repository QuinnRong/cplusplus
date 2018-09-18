#include <iostream>
#include <cstdio>

using namespace std;

int getN(int target)
{
	int res = 1;
	int sum = res * (res + 1) / 2;
	while (sum <= target)
	{
		if (sum == target)
			return res;
		++res;
		sum = res * (res + 1) / 2;
	}
	return -1;
}

int getMin(int N, int x)
{
	// cout << N << " " << x << endl;
	int res = 0;
	while (x > 0 && N > 0)
	{
		++res;
		x -= N;
		--N;
	}
	if (x <= 0) return res;
	else return -1;
}

int main()
{
	freopen("2.txt", "r", stdin);
	int x, y;
	cin >> x >> y;

	int sum = x + y;
	int N = getN(sum);

	if (N <= 0)
	{
		cout << -1 << endl;
		return 0;
	}

	int res = getMin(N, x);
	if (res < 0)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		cout << res << endl;
		return 0;
	}
}