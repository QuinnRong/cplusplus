#include <cstdio>

void PrintCircle(int** matrix, int rows, int cols, int start)
{
	int endC = cols - 1 - start;
	int endR = rows - 1 - start;

	for (int c = start; c <= endC; ++c)
	{
		printf("%d ", matrix[start][c]);
	}

	for (int r = start + 1; r <= endR; ++r)
	{
		printf("%d ", matrix[r][endC]);
	}

	for (int c = endC - 1; c >= start; --c)
	{
		printf("%d ", matrix[endR][c]);
	}

	for (int r = endR - 1; r > start; --r)
	{
		printf("%d ", matrix[r][start]);
	}
}

void PrintMatrix(int** matrix, int rows, int cols)
{
	if (matrix == nullptr || *matrix == nullptr || rows <= 0 || cols <= 0)
		return;
	for (int start = 0; start <= (rows - 1) / 2 && start <= (cols - 1) / 2; ++start)
	{
		PrintCircle(matrix, rows, cols, start);
		printf("\n");
	}
}

int main()
{
	// int matrix[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	int** matrix;
	matrix = new int*[4];
	for (int i = 0; i < 4; ++i)
		matrix[i] = new int[4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			matrix[i][j] = i * 4 + j + 1;
			printf("%4d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	PrintMatrix(matrix, 4, 4);
}