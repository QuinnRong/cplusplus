#include <iostream>
#include <cstdio>

using namespace std;

/*
INSERTION-SORT(A)
for i = 2 to A.length
	key = A[i]
	j = i - 1
	while j > 0 and A[j] > key
		A[j + 1] = A[j]
		j = j - 1
	A[j + 1] = key
*/

void InsertionSort(int* arr, int length)
{
	if (length <= 1 || arr == nullptr) return;
	for (int i = 1; i < length; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
	return;
}

int main()
{
	freopen("01.txt", "r", stdin);
	int length;
	cin >> length;
	int* arr = new int[length];
	for (int i = 0; i < length; ++i)
		cin >> arr[i];

	InsertionSort(arr, length);

	for (int i = 0; i < length; ++i)
		cout << arr[i] << " ";
	cout << endl;
	
	delete[] arr;
	fclose(stdin);
	return 0;
}
