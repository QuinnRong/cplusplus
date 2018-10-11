#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void PrimeNumbersVector(int N)
{	/*
	store primes in a vector, and judge the next value using the elements in the vector.
	*/
	vector<int> primes;
	for (int i = 2; i <= N; ++i)
	{
		bool flag = true;
		for (auto prime : primes)
		{
			if (i % prime == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			primes.push_back(i);
			printf("%d ", i);
		}
	}
	printf("\n");
}

void PrimeNumbersArray(int N)
{	/*
	store the flags in an array, and for any prime, set its multiplies as false.
	*/
	bool* flag = new bool[N + 1];
	for (int i = 0; i <= N; ++i) flag[i] = true;
	flag[0] = false;
	flag[1] = false;
	for (int i = 2; i <= N; ++i)
	{
		if (flag[i])
		{
			int mul = i + i;
			while (mul <= N)
			{
				flag[mul] = false;
				mul += i;
			}
		}
	}
	for (int i = 0; i <= N; ++i)
	{
		if (flag[i]) printf("%d ", i);
	}
	printf("\n");
	delete[] flag;
}

int main()
{
	freopen("2.txt", "r", stdin);
	int N;
	cin >> N;

	PrimeNumbersVector(N);
	PrimeNumbersArray(N);

	fclose(stdin);
	return 0;
}