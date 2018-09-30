#include <cstdio>
#include <stdexcept>
#include <cstring>

int FindGreatestSubArray(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		throw std::runtime_error("Invalid Params!");

	int res = numbers[0];
	int sum = res;
	for (int i = 1; i < length; ++i)
	{
		if (sum < 0)
			sum = numbers[i];
		else
			sum += numbers[i];
		if (sum > res)
			res = sum;
	}

	return res;
}

int FindCore(int* numbers, int* sumArray, int idx)
{
	if (idx < 0) throw std::runtime_error("Invalid Params!");
	if (idx == 0) 
	{
		sumArray[idx] = numbers[idx];
		return sumArray[idx];
	}
	int max = FindCore(numbers, sumArray, idx - 1);
	if (sumArray[idx - 1] > 0)
		sumArray[idx] = numbers[idx] + sumArray[idx - 1];
	else
		sumArray[idx] = numbers[idx];
	if (sumArray[idx] > max) max = sumArray[idx];
	return max;
}

int FindGreatestSubArrayDP(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		throw std::runtime_error("Invalid Params!");

	int* sumArray = new int[length];

	return FindCore(numbers, sumArray, length - 1);
}

int main()
{
	int arr[] = {1,-2,3,10,-4,7,2,-5};
	printf("%d\n", FindGreatestSubArray(arr, sizeof(arr) / sizeof(arr[0])));
	printf("%d\n", FindGreatestSubArrayDP(arr, sizeof(arr) / sizeof(arr[0])));
}