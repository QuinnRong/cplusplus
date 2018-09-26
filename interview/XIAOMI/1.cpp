#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <stack>
#include <cstdio>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
bool miHomeGiftBag(vector < int > p, int M) {

    sort(p.begin(), p.end());

    int sum = p[0];
    stack<int> S;
    S.push(0);
    int curr = 0;
 
    while(true)
    {
        if(sum < M)
        {
            ++curr;
            if(curr < p.size())
            {
                S.push(curr);
                sum += p[curr];
            }
            else
            {
                if(S.empty())
                    return false;
                else
                {
                    curr = S.top();
                    S.pop();
                    sum -= p[curr];
                }
            }
        }

        else if(sum > M)
        {
            if(S.size() < 2)
                return false;
            else 
            {
                sum -= p[S.top()];
                S.pop();
                sum -= p[S.top()];
                curr = S.top();
                S.pop();
            }
        }
        else return true;
    }
}
/******************************结束写代码******************************/


int main() {
    freopen("1.txt", "r", stdin);

    bool res;

    int _p_size = 0;
    cin >> _p_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _p;
    int _p_item;
    for(int _p_i=0; _p_i<_p_size; _p_i++) {
        cin >> _p_item;
        // cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _p.push_back(_p_item);
    }


    int _M;
    cin >> _M;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = miHomeGiftBag(_p, _M);
    cout << res << endl;
    
    return 0;

}
