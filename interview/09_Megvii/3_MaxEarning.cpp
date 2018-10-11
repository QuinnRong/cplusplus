#include <iostream>
#include <cstdio>

using namespace std;

int MaxEarning(const int* data, int N)
{	/*
	keep track of min value and compute diff between curr value and min value.
	*/
	if (N <= 1) return 0;
	int minVal = data[0];
	int res = 0x80000000;
	for (int i = 1; i < N; ++i)
	{
		int diff = data[i] - minVal;
		if (diff > res) res = diff;
		if (data[i] < minVal) minVal = data[i];
	}
	return res;
}

int main()
{
	freopen("3.txt", "r", stdin);
	int N;
	cin >> N;
	int* data = new int[N];
	for (int i = 0; i < N; ++i) cin >> data[i];

	int res = MaxEarning(data, N);
	printf("%d\n", res);

	delete[] data;
	fclose(stdin);
	return 0;
}