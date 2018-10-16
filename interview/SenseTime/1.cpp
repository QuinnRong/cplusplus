#include <iostream>
#include <cstdio>

using namespace std;

int MinStep(int** data, int N, int M)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int main()
{
	freopen("1.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	int** data = new int*[N];
	for (int i = 0; i < N; ++i)
	{
		data[i] = new int[M];
		for (int j = 0; j < M; ++j)
		{
			cin >> data[i][j];
		}
	}

	int res = MinStep(data, N, M);

	cout << res << endl;
	fclose(stdin);
	return 0;
}