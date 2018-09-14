#include <cstdio>

void Merge(int *data, int *copy, int left, int mid, int right)
{
	int LPos = left, RPos = mid + 1, TmpPos = left;
	while (LPos <= mid && RPos <= right)
	{
		if (data[LPos] > data[RPos])
			copy[TmpPos++] = data[RPos++];
		else
			copy[TmpPos++] = data[LPos++];
	}
	while (LPos <= mid)
		copy[TmpPos++] = data[LPos++];
	while (RPos <= right)
		copy[TmpPos++] = data[RPos++];
	for (int i = left; i < TmpPos; ++i)
		data[i] = copy[i];
}

void MergeSortCore(int *data, int *copy, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	MergeSortCore(data, copy, left, mid);
	MergeSortCore(data, copy, mid + 1, right);
	Merge(data, copy, left, mid, right);
}


void MergeSort(int *data, int length)
{
	if (data == nullptr || length <= 0) return;
	int *copy = new int[length];
	MergeSortCore(data, copy, 0, length - 1);
	delete[] copy;
}


int main()
{
	int arr[] = {5,65,48,21,3,6,94,2,0,12,36,48};
	MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
}