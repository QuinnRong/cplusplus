#include <iostream>
#include <cstdio>

using namespace std;

#define REPETITION 10000

/*
HIRE-ASSISTANT(n)
// randomly permute the list of candidates, used for RANDOMIZED-HIRE-ASSISTANT
best = 0
for i = 1 to n
	interview candidate i
	if candidate i is better than candidate best
		best = i
		hire candidate i
*/

int HireAssistant(int* candidate, int n)
{
	int cost = 0;
	int best = -1;
	for (int i = 0; i < n; ++i)
	{
		if (candidate[i] >= best)
		{
			best = candidate[i];
			++cost;
		}
	}
	return cost;
}

int main()
{
	freopen("01.txt", "r", stdin);
	int n;
	cin >> n;
	int* candidate = new int[n];

	long long totalCost = 0;
	for (int j = 0; j < REPETITION; ++j)
	{
		for (int i = 0; i < n; ++i)
			candidate[i] = rand();
		totalCost += HireAssistant(candidate, n);
	}
	printf("Average cost = %.6f\n", totalCost * 1.0 / REPETITION);

	double cost = 0;
	printf("Expected cost = ");
	for (int i = 1; i <= n; ++i)
	{
		printf("+1/%d", i);
		cost += 1.0 / i;
	}
	printf(" = %.6f\n", cost);

	delete[] candidate;
	fclose(stdin);
	return 0;
}