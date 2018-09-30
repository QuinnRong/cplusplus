#include <cstdio>
#include <stdexcept>
#include <set>

void GetLeastNumbers(int* numbers, int length, int k)
{
	if (numbers == nullptr || length <= 0)
		throw std::runtime_error("Invalid Parameters");

	std::multiset<int, std::greater<int>> intSet;
	for (int i = 0; i < k; ++i)
		intSet.insert(numbers[i]);

	for (int i = k; i < length; ++i)
	{
		if (numbers[i] < *intSet.begin())
		{
			intSet.erase(intSet.begin());
			intSet.insert(numbers[i]);
		}
	}

	for (auto iter = intSet.rbegin(); iter != intSet.rend(); ++iter)
		printf("%d\n", *iter);
	printf("\n");
}

int main()
{
	int arr[] = {4,5,1,6,2,7,3,8};
	int k = 4;
	GetLeastNumbers(arr, sizeof(arr)/sizeof(arr[0]), k);
}