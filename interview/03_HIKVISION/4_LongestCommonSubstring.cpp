#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int LCSubstring(const string& X, const string& Y)
{	/*
	time: O(X.size()*Y.size())
	space: O(X.size()*Y.size())
	*/
	int** c = new int*[X.size() + 1];
	for (int i = 0; i <= X.size(); ++i) c[i] = new int[Y.size() + 1];

	for (int i = 0; i <= X.size(); ++i) c[i][0] = 0;
	for (int j = 0; j <= Y.size(); ++j) c[0][j] = 0;

	int res = 0, row = 0, col = 0;
	for (int i = 1; i <= X.size(); ++i)
	{
		for (int j = 1; j <= Y.size(); ++j)
		{
			if (X[i - 1] == Y[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = 0;
			if (c[i][j] > res)
			{
				res = c[i][j];
				row = i;
				col = j;
			}
			// cout << c[i][j] << " ";
		}
		// cout << endl;
	}

	// print a longest-common-substring:
	for (int i = 0; i < res; ++i)
	{
		cout << X[row - res + i];
	}
	cout << endl;

	delete[] c;
	return res;
}

int main()
{
	freopen("4.txt", "r", stdin);
	string X, Y;
	cin >> X >> Y;
	cout << LCSubstring(X, Y) << endl;
	fclose(stdin);
	return 0;
}