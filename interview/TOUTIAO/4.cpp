#include <iostream>
#include <cstdio>

using namespace std;

bool isOne(unsigned int num, int idx)
{
    if (num & (1 << idx)) return true;
    return false;
}

int main(){
    freopen("4.in","r",stdin);
    int n;
    cin >> n;
    unsigned int data[4];
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
        if (data[i] >= 255)
        {
            cout << 0 << endl;
            return 0;
        }
        // cout << data[i] << endl;
    }

    if (n == 1)
    {
        cout << (isOne(data[0], 7)?0:1) << endl;
    }

    if (n == 2)
    {
        if (isOne(data[0], 7) && isOne(data[0], 6) && !isOne(data[0], 5))
        {
            if (isOne(data[1], 7) && !isOne(data[1], 6))
                cout << 1 << endl;
        }
        cout << 0 << endl;
    }

    if (n == 3)
    {
        if (isOne(data[0], 7) && isOne(data[0], 6) && isOne(data[0], 5) && !isOne(data[0], 4))
        {
            if (isOne(data[1], 7) && !isOne(data[1], 6) && isOne(data[2], 7) && !isOne(data[2], 6))
                cout << 1 << endl;
        }
        cout << 0 << endl;
    }

    if (n == 4)
    {
        if (isOne(data[0], 7) && isOne(data[0], 6) && isOne(data[0], 5) && isOne(data[0], 4) && !isOne(data[0], 3))
        {
            if (isOne(data[1], 7) && !isOne(data[1], 6) && isOne(data[2], 7) && !isOne(data[2], 6) && isOne(data[3], 7) && !isOne(data[3], 6))
                cout << 1 << endl;
        }
        cout << 0 << endl;
    }

    return 0;
}