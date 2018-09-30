#include <cstdio>

int GetFirst(int *arr, int length, int target)
{
	int left = 0, right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == target)
		{
			if (mid == 0 || arr[mid - 1] != target)
				return mid;
			right = mid - 1;
		}
		else if (arr[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int GetLast(int *arr, int length, int target)
{
	int left = 0, right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == target)
		{
			if (mid == length - 1 || arr[mid + 1] != target)
				return mid;
			left = mid + 1;
		}
		else if (arr[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int GetNumberOfK(int *arr, int length, int target)
{
	int left = GetFirst(arr, length, target);
	int right = GetLast(arr, length, target);
	if (left < 0 || right < 0) return -1;
	return (right - left + 1);
}

int main()
{
	int arr[] = {1,2,3,3,3,3,4,5};
	printf("%d\n", GetNumberOfK(arr, sizeof(arr) / sizeof(arr[0]), 3));
	printf("%d\n", GetNumberOfK(arr, sizeof(arr) / sizeof(arr[0]), 4));
}