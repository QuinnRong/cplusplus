#include <cstdio>

int BinarySearch(int *arr, int length, int target)
{
	int left = 0, right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main()
{
	int arr[] = {1,5,31,62,84,90,100};
	printf("%d\n", BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 5));
}