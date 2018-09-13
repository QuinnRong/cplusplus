#include <cstdio>
#include <stdexcept>
#include <cstring>

int GetMaxValue(int *values, int rows, int cols, int row, int col, int *count)
{
	if (row < 0 || row >= rows || col < 0 || col >= cols)
		return 0;
	if (count[row * cols + col] > 0) return count[row * cols + col];
	int down = GetMaxValue(values, rows, cols, row + 1, col, count);
	int right = GetMaxValue(values, rows, cols, row, col + 1, count);
	return (down > right) ? down + values[row * cols + col] : right + values[row * cols + col];
}

int GetMaxValue(int *values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0)
		throw std::runtime_error("Invalid Params!");

	int *count = new int[rows * cols];
	memset(count, 0, sizeof(int) * rows * cols);
	return GetMaxValue(values, rows, cols, 0, 0, count);
}

int main()
{
	int values[] = {1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};
	int res = GetMaxValue(values, 4, 4);
	printf("%d\n", res);
}