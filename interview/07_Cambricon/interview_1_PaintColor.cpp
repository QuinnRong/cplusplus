#include <cstdio>
#include <iostream>

using namespace std;

int PaintColor(int** price, int N)
{
	if (price == nullptr || N <= 0) return -1;
	int** dp = new int*[N];
	for (int i = 0; i < 3; ++i)
	{
		dp[i] = new int[N];
	}

	dp[0][0] = price[0][0];
	dp[1][0] = price[1][0];
	dp[2][0] = price[2][0];

	for (int i = 1; i < N; ++i)
	{
		dp[0][i] = price[0][i] + ((dp[1][i - 1] > dp[2][i - 1]) ? dp[2][i - 1] : dp[1][i - 1]);
		dp[1][i] = price[1][i] + ((dp[0][i - 1] > dp[2][i - 1]) ? dp[2][i - 1] : dp[0][i - 1]);
		dp[2][i] = price[2][i] + ((dp[0][i - 1] > dp[1][i - 1]) ? dp[1][i - 1] : dp[0][i - 1]);
	}

	int min = dp[0][N - 1];
	if (dp[1][N - 1] < min) min = dp[1][N - 1];
	if (dp[2][N - 1] < min) min = dp[2][N - 1];
	return min;
}

int main()
{
	freopen("interview_1.txt", "r", stdin);
	int N;
	cin >> N;

	int** price = new int*[3];
	for (int i = 0; i < 3; ++i)
	{
		price[i] = new int[N];
		for (int j = 0; j < N; ++j)
			cin >> price[i][j];
	}

	int res = PaintColor(price, N);
	printf("%d\n", res);

	delete[] price;
	fclose(stdin);
	return 0;
}