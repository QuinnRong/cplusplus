#include <iostream>
#include <cstdio>

using namespace std;

/*
MERGE(A, p, q, r)
n1 = q - p + 1
n2 = r - q
let L[1..n1+1] and R[1..n2+1] be new arrays
for i = 1 to n1
	L[i] = A[p + i - 1]
for j = 1 to n2
	R[j] = A[q + j]
L[n1 + 1] = ∞
R[n2 + 1] = ∞
i = 1
j = 1
for k = p to r
	if L[i] <= R[j]
		A[k] = L[i]
		i = i + 1
	else
		A[k] = R[j]
		j = j + 1

MERGE-Sort(A, p, r)
if p < r
	q = floor[(p + r) / 2]
	MERGE-SORT(A, p, q)
	MERGE-SORT(A, q + 1, r)
	MERGE(A, p, q, r)
*/

void Merge(int* arr, int p, int q, int r)
{	/*
	requirement: p <= q < r
	*/
	int n1 = q - p + 1;	// p ~ q
	int n2 = r - q;		// q + 1 ~ r
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	for (int i = 0; i < n1; ++i)
		L[i] = arr[p + i];
	for (int i = 0; i < n2; ++i)
		R[i] = arr[q + i + 1];
	L[n1] = 0x7fffffff;
	R[n2] = 0x7fffffff;

	int i = 0, j = 0;
	for (int k = p; k <= r; ++k)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			++i;
		}
		else
		{
			arr[k] = R[j];
			++j;
		}
	}
}

void MergeSort(int* arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}

int main()
{
	freopen("03.txt", "r", stdin);
	int length;
	cin >> length;
	int* arr = new int[length];
	for (int i = 0; i < length; ++i)
		cin >> arr[i];

	MergeSort(arr, 0, length - 1);

	for (int i = 0; i < length; ++i)
		cout << arr[i] << " ";
	cout << endl;
	
	delete[] arr;
	fclose(stdin);
	return 0;
}
