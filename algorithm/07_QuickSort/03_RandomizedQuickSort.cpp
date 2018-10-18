#include <iostream>
#include <cstdio>

using namespace std;

template <class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

/*
RANDOMIZED-QUICKSORT(A, p, r)
if p < r
	q = RANDOMIZED-PARTITION(A, p, r)
	QUICKSORT(A, p, q - 1)
	QUICKSORT(A, q + 1, r)
*/

/*
RANDOMIZED-PARTITION(A, p, r)
i = RANDOM(p, r)
swap A[i] with A[r]
return PARTITION(A, p, r)
*/

int RandomizedPartition(int* arr, int p, int r)
{
	int random = rand() % (p - r + 1) + p;
	Swap(arr[r], arr[random]);

	int x = arr[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)
	{
		if (arr[j] <= x)
		{
			Swap(arr[++i], arr[j]);
		}
	}
	Swap(arr[++i], arr[r]);
	return i;
}

void RandomizedQuickSort(int* arr, int p, int r)
{
	if (p < r)
	{
		int q = RandomizedPartition(arr, p, r);
		RandomizedQuickSort(arr, p, q - 1);
		RandomizedQuickSort(arr, q + 1, r);
	}
}

int main()
{
	freopen("03.txt", "r", stdin);
	int len;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; ++i)
		cin >> arr[i];

	RandomizedQuickSort(arr, 0, len - 1);

	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;

	delete[] arr;
	fclose(stdin);
	return 0;
}
