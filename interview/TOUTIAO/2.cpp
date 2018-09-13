#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void VisitCore(int* matrix, int rows, int cols, int row, int col, bool* isVisited)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols) return;
    int idx = row * cols + col;
    if (matrix[idx] == 0 || isVisited[idx]) return;
    isVisited[idx] = true;
    VisitCore(matrix, rows, cols, row + 1, col, isVisited);
    VisitCore(matrix, rows, cols, row - 1, col, isVisited);
    VisitCore(matrix, rows, cols, row, col + 1, isVisited);
    VisitCore(matrix, rows, cols, row, col - 1, isVisited);
}

int main(){
    // freopen("2.in","r",stdin);
    int n;
    cin >> n;
    int* matrix = new int[n * n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; scanf("%d",&x);
            matrix[i * n + j] = x;
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << matrix[i * n + j] << " ";
    //     }
    //     cout << endl;
    // }

    bool* isVisited = new bool[n * n];
    memset(isVisited, false, n*n*sizeof(bool));

    int res =0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (matrix[i * n + j] == 1 && !isVisited[i * n + j])
            {
                ++res;
                VisitCore(matrix, n, n, i, j, isVisited);
            }
        }
    }
    cout << res << endl;
}