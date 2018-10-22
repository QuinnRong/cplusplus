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
QUICKSORT(A, p, r)
if p < r
	q = PARTITION(A, p, r)
	QUICKSORT(A, p, q - 1)
	QUICKSORT(A, q + 1, r)
*/

/*
PARTITION(A, p, r)
x = A[r]
i = p - 1			// last element of the left array
for j = p to r - 1	// last element of the right array
	if A[j] < x
		i = i + 1
		swap A[i] with A[j]
swap A[i + 1] with A[r]
return i + 1

or equivalently:

PARTITION(A, p, r)
x = A[p]
i = p				// last element of the left array
for j = p + 1 to r	// last element of the right array
	if A[j] < x
		i = i + 1
		swap A[i] with A[j]
swap A[i] with A[r]
return i
*/

int Partition_bk(int* arr, int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)
	{
		if (arr[j] < x)
		{
			Swap(arr[++i], arr[j]);
		}
	}
	Swap(arr[++i], arr[r]);
	return i;
}

int Partition(int* arr, int p, int r)
{
	int x = arr[p];
	int i = p;
	for (int j = p + 1; j <= r; ++j)
	{
		if (arr[j] < x)
		{
			Swap(arr[++i], arr[j]);
		}
	}
	Swap(arr[i], arr[p]);
	return i;
}

void QuickSort(int* arr, int p, int r)
{
	if (p < r)
	{
		int q = Partition(arr, p, r);
		QuickSort(arr, p, q - 1);
		QuickSort(arr, q + 1, r);
	}
}

int main()
{
	freopen("01.txt", "r", stdin);
	int len;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; ++i)
		cin >> arr[i];

	QuickSort(arr, 0, len - 1);

	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;

	delete[] arr;
	fclose(stdin);
	return 0;
}
