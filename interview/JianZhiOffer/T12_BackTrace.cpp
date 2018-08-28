#include <cstdio>
#include <cstring>

bool hasPathCore(char* matrix, bool* visited, int rows, int cols, int row, int col, char* str, int idx)
{
	if (str[idx] == '\0') return true;
	if (row >= 0 && row < rows && col >= 0 && col < cols && idx >= 0)
	{
		if (!visited[row * cols + col] && matrix[row * cols + col] == str[idx])
		{
			visited[row * cols + col] = true;
			if (hasPathCore(matrix, visited, rows, cols, row-1, col, str, idx+1) ||
				hasPathCore(matrix, visited, rows, cols, row+1, col, str, idx+1) ||
				hasPathCore(matrix, visited, rows, cols, row, col-1, str, idx+1) ||
				hasPathCore(matrix, visited, rows, cols, row, col+1, str, idx+1))
			{
				return true;
			}
			else
			{
				visited[row * cols + col] = false;
			}

		}
	}
	return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || rows <= 0 || cols <= 0) return false;
	bool* visited = new bool[rows * cols];
	memset(visited, false, rows * cols * sizeof(bool));
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(matrix, visited, rows, cols, row, col, str, 0))
			{
				delete[] visited;
				return true;
			}
		}
	}
	delete[] visited;
	return false;
}

int main()
{
	char matrix[] = {'a','b','t','g','c','f','c','s','j','d','e','h'};
	char str1[] = "bfce";
	char str2[] = "abfb";
	printf("%s\n", hasPath(matrix, 4, 4, str1)?"true":"false");
	printf("%s\n", hasPath(matrix, 4, 4, str2)?"true":"false");
}