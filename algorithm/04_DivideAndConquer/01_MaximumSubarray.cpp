#include <iostream>
#include <cstdio>

using namespace std;

/*
BRUTE-FORCE(A)
max-sum = -∞
for i = 1 to A.length
	sum = 0
	for j = i to A.length
		sum = sum + A[j]
		if sum > max-sum
			max-sum = sum
			low = i
			high = j
return (low, high, max-sum)
*/

void BruteForce(int* arr, int length, int& low, int& high, int& maxSum)
{	/*
	time: O(n*n)
	*/
	maxSum = 0x80000000;
	for (int i = 0; i < length; ++i)
	{
		int sum = 0;
		for (int j = i; j < length; ++j)
		{
			sum += arr[j];
			if (sum > maxSum)
			{
				maxSum = sum;
				low = i;
				high = j;
			}
		}
	}
}

/*
FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
left-sum = -∞
sum = 0
for i = mid downto low
	sum = sum + A[i]
	if sum > left-sum
		left-sum = sum
		cross-left = i
right-sum = -∞
sum = 0
for j = mid + 1 to high
	sum = sum + A[j]
	if sum > right-sum
		right-sum = sum
		cross-right = j
return (cross-left, cross-right, left-sum + right-sum)

FIND-MAXIMUM-SUBARRAY(A, low, high)
if high == low
	return (low, high, A[low])
else mid = floor[(low + high) / 2]
	(left-low, left-high, left-sum) = 
		FIND-MAXIMUM-SUBARRAY(A, low, mid)
	(right-low, right-high, right-sum) = 
		FIND-MAXIMUM-SUBARRAY(A, mid + 1, high)
	(cross-low, cross-high, cross-sum) = 
		FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
	if left-sum >= right-sum and left-sum >= cross-sum
		return (left-low, left-high, left-sum)
	elseif right-sum >= left-sum && right-sum >= cross-sum
		return (right-low, right-high, right-sum)
	else
		return (cross-low, cross-high, cross-sum)
*/

void FindMaxCrossSubarray(int* arr, int low, int mid, int high, 
							int& crossLow, int& crossHigh, int& crossSum)
{
	int leftSum = 0x80000000;
	int sum = 0;
	for (int i = mid; i >= low; --i)
	{
		sum += arr[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			crossLow = i;
		}
	}
	int rightSum = 0x80000000;
	sum = 0;
	for (int j = mid + 1; j <= high; ++j)
	{
		sum += arr[j];
		if (sum > rightSum)
		{
			rightSum = sum;
			crossHigh = j;
		}
	}
	crossSum = leftSum + rightSum;
}

void FindMaxSubarrayCore(int* arr, int start, int end, int& low, int& high, int& maxSum)
{	/*
	time: O(n*logn)
	*/
	if (end == start)
	{
		low = start;
		high = end;
		maxSum = arr[start];
	}
	else
	{
		int mid = (start + end) / 2;
		int leftLow, leftHigh, leftSum;
		FindMaxSubarrayCore(arr, start, mid, leftLow, leftHigh, leftSum);
		int rightLow, rightHigh, rightSum;
		FindMaxSubarrayCore(arr, mid + 1, end, rightLow, rightHigh, rightSum);
		int crossLow, crossHigh, crossSum;
		FindMaxCrossSubarray(arr, start, mid, end, crossLow, crossHigh, crossSum);
		if (leftSum >= rightSum && leftSum >= crossSum)
		{
			low = leftLow;
			high = leftHigh;
			maxSum = leftSum;
		}
		else if (rightSum >= leftSum && rightSum >= crossSum)
		{
			low = rightLow;
			high = rightHigh;
			maxSum = rightSum;
		}
		else
		{
			low = crossLow;
			high = crossHigh;
			maxSum = crossSum;
		}
	}
}

void FindMaxSubarray(int* arr, int length, int& low, int& high, int& maxSum)
{
	FindMaxSubarrayCore(arr, 0, length - 1, low, high, maxSum);
}

/*
FIND-MAX-SUBARRAY-LINEAR(A)
max-sum = -∞
sum = 0
low-prev = 1
for i = 1 to A.length
	sum  = sum + A[i]
	if sum > max-sum
		max-sum = sum
		low = low-prev
		high = i
	if sum < 0
		sum = 0
		low = low-prev
		low-prev = i + 1
return (low, high, max-sum)
*/

void FindMaxSubarrayLinear(int* arr, int length, int& low, int& high, int& maxSum)
{	/*
	time: O(n)
	*/
	maxSum = 0x80000000;
	int sum = 0;
	int lowPrev = 0;
	for (int i = 0; i < length; ++i)
	{
		sum += arr[i];
		if (sum > maxSum)
		{
			maxSum = sum;
			low = lowPrev;
			high = i;
		}
		if (sum < 0)
		{
			sum = 0;
			lowPrev = i + 1;
		}
	}
}

int main()
{
	freopen("01.txt", "r", stdin);
	int length;
	cin >> length;
	int* arr = new int[length];
	for (int i = 0; i < length; ++i)
		cin >> arr[i];

	int low, high, maxSum;
	BruteForce(arr, length, low, high, maxSum);
	cout << "BruteForce: ";
	cout << low << " " << high << " " << maxSum << endl;

	FindMaxSubarray(arr, length, low, high, maxSum);
	cout << "Logarithm:  ";
	cout << low << " " << high << " " << maxSum << endl;
	
	FindMaxSubarrayLinear(arr, length, low, high, maxSum);
	cout << "Linear:     ";
	cout << low << " " << high << " " << maxSum << endl;

	delete[] arr;
	fclose(stdin);
	return 0;
}