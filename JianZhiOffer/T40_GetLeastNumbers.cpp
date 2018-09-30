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

int Partition(int* numbers, int length, int left, int right)
{
	if (numbers == nullptr || length <= 0 || left < 0 || right >= length)
		throw std::runtime_error("Invalid Params!");

	int index = MinOfThree(numbers, left, (left + right) / 2, right);
	Swap(&numbers[index], &numbers[right]);

	int small = left;
	int large = right - 1;
	while (small < large)
	{
		while (numbers[small] < numbers[right]) ++small;
		while (numbers[large] > numbers[right]) --large;
		Swap(&numbers[small], &numbers[large]);
		++small;
		--large;
	}

	Swap(&numbers[small], &numbers[right]);
	return small;
}

void GetLeastNumbers(int* numbers, int length, int k)
{
	if (numbers == nullptr || length <= 0)
		throw std::runtime_error("Invalid Parameters");
	int left = 0, right = length - 1;
	int index = Partition(numbers, length, left, right);
	while (index != k)
	{
		if (index < k) left = index + 1;
		if (index > k) right = index - 1;
		index = Partition(numbers, length, left, right);
	}
}

int main()
{
	int arr[] = {4,5,1,6,2,7,3,8};
	int k = 4;
	GetLeastNumbers(arr, sizeof(arr)/sizeof(arr[0]), k);
	for (int i = 0; i < k; ++i)
		printf("%d\n", arr[i]);
}