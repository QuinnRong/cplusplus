#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int TriangleNum(int a, int b, int c)
{	/*
	time: O(n^2)
	*/
	int res = 0;
	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			int min = abs(i - j) + 1;
			int max = abs(i + j) - 1;
			if (max > c) max = c;
			int num = max - min + 1;
			if (num > 0) res += num;
		}
	}
	return res;
}

int main()
{
	freopen("3.txt", "r", stdin);
	int a, b, c;
	cin >> a >> b >> c;

	int res = TriangleNum(a, b, c);
	cout << res << endl;
	fclose(stdin);
	return 0;
}