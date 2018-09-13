#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool find(vector<vector<int>> &matrix, int number)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	int row = 0, col = cols - 1;
	while (row < rows && col >= 0)
	{
		if (matrix[row][col] > number) --col;
		else if (matrix[row][col] < number) ++row;
		else return true;
	}
	return false;
}

int main(){
    freopen("1.in","r",stdin);

    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix;
    for(int r = 0; r < rows; r++){
    	vector<int> tmp;
        for(int c = 0; c < cols; c++){
            int x; scanf("%d", &x);
            tmp.push_back(x);
        }
        matrix.push_back(tmp);
    }
    int number;
    cin >> number;

    printf("%s\n", find(matrix, number) ? "true":"false");

    // for (auto row : matrix)
    // {
    // 	for (auto x : row)
    // 		cout << x << " ";
    // 	cout << endl;
    // }

    return 0;
}