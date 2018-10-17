#include <iostream>
#include <cstdio>

using namespace std;

#define REPETITION 1000000

void PrefixFun(const int* P, int len, int* pi)
{
	int i = 0, q = 0;
	pi[i] = q;
	for (i = 1; i < len; ++i)
	{
		while (q > 0 && P[i] != P[q]) q = pi[q - 1];
		if (P[i] == P[q]) ++q;
		pi[i] = q;
	}
}

double ExpectStep(int* P, int len)
{
	int* pi = new int[len];
	PrefixFun(P, len, pi);
	// cout << "Prefix Function: ";
	// for (int i = 0; i < len; ++i) cout << pi[i] << " ";
	// cout << endl;
	
	long long sum = 0;
	for (int j = 0; j < REPETITION; ++j)
	{
		int q = 0;
		int step = 0;
		while (1)
		{
			int T = rand() % 2;
			++step;
			// cout << T << " ";
			while (q > 0 && T != P[q]) q = pi[q - 1];
			if (T == P[q]) ++q;
			if (q == len)
			{
				// cout << "->" << step << endl;
				sum += step;
				break;
			}
		}
	}

	return sum * 1.0 / REPETITION;
}

int main()
{
	freopen("04-3.txt", "r", stdin);
	int n;
	cin >> n;
	int* pattern = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> pattern[i];

	double expect = ExpectStep(pattern, n);

	cout << expect << endl;

	delete[] pattern;
	fclose(stdin);
	return 0;
}