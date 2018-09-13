#include <cstdio>
#include <stdexcept>

#define MinOfThree(data,a,b,c) (data[a]>data[b]?\
				(data[b]>data[c]?b:(data[a]>data[c]?c:a)):\
				(data[a]>data[c]?a:(data[b]>data[c]?c:b)))

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Partition(int *data, int length, int left, int right)
{
	if (data == nullptr || length <= 0 || left < 0 || right >= length)
		throw std::runtime_error("Invalid Params!");

	int index = MinOfThree(data, left, (left + right) / 2, right);
	Swap(&data[index], &data[right]);

	int small = left;
	for (index = left; index < right; ++index)
	{
		if (data[index] < data[right])
		{
			if (small != index)
			{
				Swap(&data[small], &data[index]);
			}
			++small;
		}
	}

	Swap(&data[small], &data[right]);
	return small;
}

void QuickSortCore(int *data, int length, int left, int right)
{
	if (left == right) return;
	int index = Partition(data, length, left, right);
	if (index > left) QuickSortCore(data, length, left, index - 1);
	if (index < right) QuickSortCore(data, length, index + 1, right);
}

void QuickSort(int *data, int length)
{
	if (data == nullptr) return;
	QuickSortCore(data, length, 0, length - 1);
}

int main()
{
	int arr[] = {5,65,48,21,3,6,94,2,0,12,36,48};
	QuickSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
}