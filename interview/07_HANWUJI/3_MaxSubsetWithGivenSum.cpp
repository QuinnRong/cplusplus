#include <cstdio>
#include <iostream>

using namespace std;

void MaxSubsetCore(int* arr, int N, int target, int idx, int& sum, int& currSize, int& maxSize)
{
	if (idx == N)
	{
		if (sum == target && currSize > maxSize)
			maxSize = currSize;
		return;
	}

	MaxSubsetCore(arr, N, target, idx + 1, sum, currSize, maxSize);	// do not select current number

	sum += arr[idx]; ++currSize;
	MaxSubsetCore(arr, N, target, idx + 1, sum, currSize, maxSize);	// select current number
	sum -= arr[idx]; --currSize;
}

int MaxSubset(int* arr, int N, int target)
{
	if (arr == nullptr || N <= 0) return 0;
	int sum = 0, currSize = 0, maxSize = 0;
	MaxSubsetCore(arr, N, target, 0, sum, currSize, maxSize);
	return maxSize;
}

int main()
{
	freopen("3.txt", "r", stdin);
	int N, target;
	cin >> N >> target;

	int* arr = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int res = MaxSubset(arr, N, target);
	printf("%d\n", res);

	fclose(stdin);
	return 0;
}