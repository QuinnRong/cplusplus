#include <cstdio>
#include <cstring>

int getDigitSum(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

bool check(int row, int col, int threshold)
{
	if (getDigitSum(row) + getDigitSum(col) > threshold) return false;
	return true;
}

int movingCountCore(bool* visited, int rows, int cols, int row, int col, int threshold)
{
	if (visited[row * cols + col] || row < 0 || row >= rows || col < 0 || col >= cols || !check(row, col, threshold)) return 0;
	int count = 1;
	visited[row * cols + col] = true;
	count += movingCountCore(visited, rows, cols, row-1, col, threshold);
	count += movingCountCore(visited, rows, cols, row+1, col, threshold);
	count += movingCountCore(visited, rows, cols, row, col-1, threshold);
	count += movingCountCore(visited, rows, cols, row, col+1, threshold);
	return count;
}

int movingCount(int rows, int cols, int threshold)
{
	bool* visited = new bool[rows * cols];
	memset(visited, false, rows * cols * sizeof(bool));
	int count = movingCountCore(visited, rows, cols, 0, 0, threshold);
	delete[] visited;
	return count;
}

int main()
{
	printf("%d\n", movingCount(2,2,2));
}