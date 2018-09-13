#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_N = 105;
int V, E;
// 代表点的颜色，初始化为0，1或-1表示两种不同的颜色
int color[MAX_N];
// 使用邻接矩阵来模拟图
int G[MAX_N][MAX_N];
 
bool bfs(int s)
{
    color[s] = 1;
    queue<int> que;
    que.push(s);
    while(!que.empty())
    {
        int from = que.front();
        que.pop();
        for(int i = 1; i <= V; i++)
        {
            // 如果相邻的点没有上色就给这个点上色
            if(G[from][i] && color[i] == 0)
            {
                que.push(i);
                color[i] = -color[from];
            }
            // 如果相邻的颜色相同则返回false
            if(G[from][i] && color[i] == color[from])
                return false;
        }
    }
    // 如果所有的点都被染过色，且相邻的点颜色都不一样，返回true
    return true;
}
 
int main()
{
    // V代表有几个点，E代表有几条边
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int s, t;
        cin >> s >> t;
        G[s][t]  = G[t][s] = 1;
    }
    bool flag = false;
    // 初始化color数组
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= V; i++)
    {
        if(color[i] == 0 && !bfs(i))
        {
            flag = true;
            break;
        }
    }
    if(flag)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
 
    return 0;
}
