#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

bool isConnected(vector<vector<int>> &matrix, vector<int> &set)
{
    if (set.size() <= 1) return false;
    for (int i = 0; i < set.size() - 1; ++i)
    {
        for (int j = i + 1; j < set.size(); ++j)
        {
            if (matrix[i][j] == 1) return true;
        }
    }
    return false;
}

bool isSuchGraph(vector<vector<int>> &matrix)
{
    for (int i = 1; i < matrix.size(); ++i)
    {
        vector<int> sameSet;
        sameSet.push_back(i);
        for (int j = 1; j < matrix.size(); ++j)
        {
            if (matrix[i][j] == 1) sameSet.push_back(j);
        }
        if (isConnected(matrix, sameSet)) return false;
    }
    return true;
}

int main(){
    freopen("2.in","r",stdin);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix;
    for (int i = 0; i <= N; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j <= N; ++j)
        {
            tmp.push_back(0);
        }
        matrix.push_back(tmp);
    }
    for(int i = 0; i < M; i++){
        int s, t;
        cin >> s >> t;
        matrix[s][t] = matrix[t][s] = 1;
    }
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (isSuchGraph(matrix)?"Yes":"No") << endl;
}