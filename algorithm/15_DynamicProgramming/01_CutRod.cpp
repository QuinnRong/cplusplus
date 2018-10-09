#include <iostream>
#include <cstdio>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))

int CutRod(int len, int* price, int N)
{	/*
	time: O(2^len)
	space: stack
	*/
	int res = 0;
	if (len <= N) res = price[len];		// to include non-cut case
	for (int i = 1; i <= len / 2; ++i)	// i represents certain cut; i cannot start from 0; len / 2 due to symmetry
	{
		int curr = CutRod(i, price, N) + CutRod(len - i, price, N);
		if (curr > res) res = curr;
	}
	return res;
}

int CutRodHalf(int len, int* price, int N)
{	/*
	time: O(2^len)
	space: stack
	*/
	int res = 0;
	for (int i = 1; i <= MIN(N, len); ++i)	// i represents first cut; i cannot start from 0
	{
		int curr = price[i] + CutRod(len - i, price, N);	// non-cut case is included if possible (when i == len)
		if (curr > res) res = curr;
	}
	return res;
}

void MemoizedCutRodAux(int len, int* price, int N, int* r)
{
	if (r[len] >= 0) return;
	for (int i = 1; i <= MIN(N, len); ++i)
	{
		MemoizedCutRodAux(len - i, price, N, r);
		int curr = price[i] + r[len - i];
		if (curr > r[len]) r[len] = curr;
	}
}

int MemoizedCutRod(int len, int* price, int N)
{	/*
	time: O(N*len)
	space: O(len) + stack
	*/
	int* r = new int[len + 1];
	r[0] = 0;
	for (int i = 1; i <= len; ++i)
		r[i] = -1;
	MemoizedCutRodAux(len, price, N, r);
	int res = r[len];
	delete[] r;
	return res;
}

int BottomUpCutRod(int len, int* price, int N)
{	/*
	time: O(N*len)
	space: O(len)
	*/
	int* r = new int[len + 1];
	r[0] = 0;
	for (int i = 1; i <= len; ++i)		// i represents length
	{
		r[i] = -1;
		for (int j = 1; j <= MIN(N, i); ++j)	// j represents first cut; j cannot start from 0
		{
			int curr = price[j] + r[i - j];
			if (curr > r[i]) r[i] = curr;
		}
	}
	int res = r[len];
	delete[] r;
	return res;
}

int ExtendedBottomUpCutRod(int len, int* price, int N)
{	/*
	time: O(N*len)
	space: O(len)
	*/
	int* r = new int[len + 1];
	int* s = new int[len + 1];
	r[0] = 0;
	for (int i = 1; i <= len; ++i)		// i represents length
	{
		r[i] = -1;
		for (int j = 1; j <= MIN(N, i); ++j)	// j represents first cut; j cannot start from 0
		{
			int curr = price[j] + r[i - j];
			if (curr > r[i]) 
			{
				r[i] = curr;
				s[i] = j;
			}
		}
	}
	int res = r[len];

	int remain = len;
	printf("len = %d, r = %d, s:", len, res);
	while (remain > 0)
	{
		printf(" %d", s[remain]);
		remain -= s[remain];
	}
	printf("\n");

	delete[] r;
	delete[] s;
	return res;
}

int main()
{
	freopen("01.txt", "r", stdin);
	int N;
	cin >> N;
	int* price = new int[N + 1];
	price[0] = 0;
	for (int i = 1; i <= N; ++i)
		cin >> price[i];

	for (int len = 0; len <= 25; ++len)
	{
		int r1 = CutRod(len, price, N);
		int r2 = CutRodHalf(len, price, N);
		int r3 = MemoizedCutRod(len, price, N);
		int r4 = BottomUpCutRod(len, price, N);
		printf("%2d -> %3d %3d %3d %3d\n", len, r1, r2, r3, r4);
	}
	ExtendedBottomUpCutRod(25, price, N);

	delete[] price;
	fclose(stdin);
	return 0;
}