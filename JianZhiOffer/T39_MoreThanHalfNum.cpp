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

int MoreThanHalfNum(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		throw std::runtime_error("Invalid Parameters");
	int left = 0, right = length - 1;
	int index = Partition(numbers, length, left, right);
	int mid = length / 2;
	while (index != mid)
	{
		if (index < mid) left = index + 1;
		if (index > mid) right = index - 1;
		index = Partition(numbers, length, left, right);
	}
	return numbers[mid];
}

int main()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int res = MoreThanHalfNum(arr, sizeof(arr)/sizeof(arr[0]));
	printf("%d\n", res);
}