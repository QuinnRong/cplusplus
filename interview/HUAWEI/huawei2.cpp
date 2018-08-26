#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int val[5], wet[5];
    int tol;

    scanf("%d,%d,%d,%d,%d",&val[0],&val[1],&val[2],&val[3],&val[4]);
    scanf("%d,%d,%d,%d,%d",&wet[0],&wet[1],&wet[2],&wet[3],&wet[4]);
    scanf("%d", &tol);

    set<int> sum;
    for (int a = 0; a < 2; ++a)
    {
        for (int b = 0; b < 2; ++b)
        {
            for (int c = 0; c < 2; ++c)
            {
                for (int d = 0; d < 2; ++d)
                {
                    for (int e = 0; e < 2; ++e)
                    {
                        if (a*wet[0] + b*wet[1] + c*wet[2] + d*wet[3] + e*wet[4] <= tol)
                        {
                            sum.insert(a*val[0] + b*val[1] + c*val[2] + d*val[3] + e*val[4]);
                        }
                    }
                }
            }
        }
    }
    
    int max = *(sum.begin());
    for (auto i : sum)
    {
        if (i > max)
        {
            max = i;
        }
    }
    cout << max << endl;
}