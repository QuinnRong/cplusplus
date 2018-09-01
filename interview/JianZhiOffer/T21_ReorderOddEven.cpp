#include <cstdio>

bool isOdd(unsigned int num)
{
	return (num & 1) == 1;
}

void Reorder(int* arr, int len, bool (*func)(unsigned int))
{
	if (arr == nullptr || len < 0) return;
	int start = 0, end = len - 1;
	while (start < end)
	{
		while (func(arr[start]) && start < end) ++start;
		while (!func(arr[end]) && start < end) --end;

		if (start < end)
		{
			int tmp = arr[start];
			arr[start] = arr[end];
			arr[end] = tmp;
			++start;
			--end;
		}
	}
}

void ReorderOddEven(int* arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] < 0)
		{
			printf("%s\n", "Negative number!");
			return;
		}
	}
	Reorder(arr, len, isOdd);
}

void PrintArr(int* arr, int len)
{
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr1[] = {1,2,3,4,5};
	PrintArr(arr1, sizeof(arr1)/sizeof(arr1[0]));
	ReorderOddEven(arr1, sizeof(arr1)/sizeof(arr1[0]));
	PrintArr(arr1, sizeof(arr1)/sizeof(arr1[0]));
}