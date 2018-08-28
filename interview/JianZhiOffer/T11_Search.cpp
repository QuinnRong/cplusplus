#include <cstdio>
#include <stdexcept>

int MinInOrder(int* numbers, int left, int right)
{
	int res = numbers[left];
	for (int i = left + 1; i < right; ++i)
	{
		if (res > numbers[i]) res = numbers[i];
	}
	return res;
}

int MinCore(int* numbers, int left, int right)
{
	printf("%d %d\n", left, right);
	if (left == right) return numbers[left];
	if (numbers[left] < numbers[right]) return numbers[left];
	if (left == right - 1) return numbers[right];
	int mid = left + (right - left) / 2;
	if (numbers[left] == numbers[right] && numbers[right] == numbers[mid])
		return MinInOrder(numbers, left, right);
	if (numbers[mid] >= numbers[left]) left = mid;
	if (numbers[mid] <= numbers[right]) right = mid;
	return MinCore(numbers, left, right);
}

int Min(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0) throw std::runtime_error("invalid input!");
	return MinCore(numbers, 0, length - 1);
}

int main()
{
	int numbers1[5] = {3,4,5,1,2};
	printf("%d\n", Min(numbers1, 5));
	int numbers2[5] = {1,2,3,4,5};
	printf("%d\n", Min(numbers2, 5));
	int numbers3[5] = {1,0,1,1,1};
	printf("%d\n", Min(numbers3, 5));
	int numbers4[5] = {1,1,1,0,1};
	printf("%d\n", Min(numbers4, 5));
}