#include <cstdio>
#include <stdexcept>

int MoreThanHalfNum(int* numbers, int length)
{
	if (numbers == nullptr || length < 0)
		throw std::runtime_error("Invalid Input!");

	int res = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (numbers[i] == res) ++times;
		else --times;
		if (times == 0)
		{
			res = numbers[i];
			times = 1;
		}
	}
	
	return res;
}

int main()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int res = MoreThanHalfNum(arr, sizeof(arr)/sizeof(arr[0]));
	printf("%d\n", res);
}