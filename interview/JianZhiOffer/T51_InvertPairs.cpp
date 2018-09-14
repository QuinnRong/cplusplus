#include <cstdio>

int Merge(int *data, int *copy, int left, int mid, int right)
{
	int LPos = left, RPos = mid + 1, TmpPos = left;
	int res = 0;
	while (LPos <= mid && RPos <= right)
	{
		if (data[LPos] > data[RPos])
		{
			res += mid - LPos + 1;
			copy[TmpPos++] = data[RPos++];
		}
		else
			copy[TmpPos++] = data[LPos++];
	}
	while (LPos <= mid)
		copy[TmpPos++] = data[LPos++];
	while (RPos <= right)
		copy[TmpPos++] = data[RPos++];

	for (int i = left; i < TmpPos; ++i)
		data[i] = copy[i];
	return res;
}

int InvertPairsCore(int *data, int *copy, int left, int right)
{
	if (left >= right) return 0;

	int res = 0;
	int mid = (left + right) / 2;
	res += InvertPairsCore(data, copy, left, mid);
	res += InvertPairsCore(data, copy, mid + 1, right);
	res += Merge(data, copy, left, mid, right);

	return res;
}

int InvertPairs(int *data, int length)
{
	if (data == nullptr || length <= 0) return 0;

	int *copy = new int[length];
	int res = InvertPairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return res;
}

int main()
{
	int data[] = {7,5,6,4};
	printf("%d\n", InvertPairs(data, sizeof(data) / sizeof(data[0])));
}