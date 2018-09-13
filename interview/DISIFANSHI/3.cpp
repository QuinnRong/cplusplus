// 一个简单的二分图的判断
 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
const int MAX_N =105;
int V,E;
// 使用邻接表模拟一张无向图
vector<int> G[MAX_N];
// 顶点的颜色,初始化为0，上色有两种颜色（0 or 1）
int color[MAX_N];
 
bool dfs(int v, int c)
{
    color[v] = c;       // 把顶点染成c
    for(int i = 0; i < G[v].size(); i++)
    {
        // 如果当前点的相邻的点同色就返回false
        if(color[G[v][i]] == c)
            return false;
        // 如果当前点的邻点还没被染色，就染成-c
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c))
            return false;
    }
    // 如果当前点都被染过色，就返回true
    return true;
}
 
void solve()
{
    for(int i = 0; i < V; i++)
    {
        if(color[i] == 0)
        {
            if(!dfs(i,1))
            {
                cout << "no" << endl;
                return;
            }
        }
    }
    cout << "yes" << endl;
}
 
int main()
{
    cin >> V >> E;
    for(int i = 0; i < E;  i++)
    {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);  // 如果有向图则无需这一句
    }
    memset(color, 0, sizeof(color));
    solve();
 
    return 0;
}
