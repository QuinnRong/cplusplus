#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    freopen("1.txt", "r", stdin);
    string str;
    cin >> str;
    fclose(stdin);

    int diff = 'a' - 'A';
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= diff;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += diff;
        }
    }
    cout << str << endl;
}

/*
result:
hELLO,wORLD!
*/