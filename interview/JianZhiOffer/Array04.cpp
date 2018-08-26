#include <cstdio>

bool find(int* matrix, int rows, int cols, int number)
{
	if (matrix == nullptr || rows <= 0 || cols <= 0) return false;
	int row = 0, col = cols - 1;
	while (row < rows && col >= 0)
	{
		if (matrix[row * cols + col] > number) --col;
		else if (matrix[row * cols + col] > number) ++row;
		else return true;
	}
	return false;
}

int main()
{
	int matrix[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	printf("%s\n", find(matrix, 4, 4, 7) ? "true":"false");
}