#include <cstdio>

bool VerifyCore(int* sequence, int start, int end)
{
	if (end - start <= 1) return true;

	int root = sequence[end];
	int mid = start;
	while (sequence[mid] < root) ++mid;
	for (int i = mid; i < end; ++i)
	{
		if (sequence[i] < root) return false;
	}
	return VerifyCore(sequence, start, mid - 1) && VerifyCore(sequence, mid, end - 1);

}

bool VerifySequenceOfBST(int* sequence, int len)
{
	if (sequence == nullptr || len <= 0) return false;
	return VerifyCore(sequence, 0, len - 1);
}

int main()
{
	int sequence1[] = {5,7,6,9,11,10,8};
	printf("%s\n", VerifySequenceOfBST(sequence1, 7)?"yes":"no");
	int sequence2[] = {7,4,6,5};
	printf("%s\n", VerifySequenceOfBST(sequence2, 4)?"yes":"no");
}