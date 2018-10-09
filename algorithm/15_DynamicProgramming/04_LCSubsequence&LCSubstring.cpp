#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

int LCSubsequence(const string& X, const string& Y)
{	/*
	time: O(X.size()*Y.size())
	space: O(X.size()*Y.size())
	*/
	int** c = new int*[X.size() + 1];
	for (int i = 0; i <= X.size(); ++i) c[i] = new int[Y.size() + 1];

	for (int i = 0; i <= X.size(); ++i) c[i][0] = 0;
	for (int j = 0; j <= Y.size(); ++j) c[0][j] = 0;

	for (int i = 1; i <= X.size(); ++i)
	{
		for (int j = 1; j <= Y.size(); ++j)
		{
			if (X[i - 1] == Y[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = MAX(c[i][j - 1], c[i - 1][j]);
			// cout << c[i][j] << " ";
		}
		// cout << endl;
	}

	// print a longest-common-subsequence: O(X.size()+Y.size())
	int row = X.size(), col = Y.size();
	while (row > 0 && col > 0)
	{
		// if (c[row - 1][col - 1] == c[row][col] - 1 &&
		// 	c[row][col - 1] == c[row][col] - 1 &&
		// 	c[row - 1][col] == c[row][col] - 1)
		if (X[row - 1] == Y[col - 1])
		{
			cout << X[row - 1];
			--row;
			--col;
		}
		else if (c[row][col - 1] > c[row - 1][col]) --col;
		else --row;
	}
	cout << endl;

	int res = c[X.size()][Y.size()];
	delete[] c;
	return res;
}

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
	freopen("04.txt", "r", stdin);
	string X, Y;
	cin >> X >> Y;
	cout << LCSubsequence(X, Y) << endl;
	cout << LCSubstring(X, Y) << endl;
	fclose(stdin);
	return 0;
}