#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    freopen("2.in","r",stdin);

    string str;
    cin >> str;
    cout << str << endl;

    // printf("%d\n", str.size());

    int* status = new int[str.size()];
    memset(status, 0, str.size() * sizeof(int));

    int left = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'L')
        {
            for (int j = left; j <= i; ++j) status[j] = -1;
            left = i;
        }
        if (str[i] == 'R')
        {
            int countL = 0;
            for (int j = i + 1; j < str.size(); ++j)
            {
                if (str[j] == 'R')
                {
                    for (int k = i; k <= j; ++k) status[k] = 1;
                    i = j;
                    left = i + 1;
                    break;
                }
                if (str[j] == 'L')
                {
                    for (int k = i; k <= (i + (j - i - 1) / 2); ++k) status[k] = 1;
                    for (int k = j; k >= (j - (j - i - 1) / 2); --k) status[k] = -1;
                    // printf("%d %d\n", i, (i + (j - i - 1) / 2));
                    // printf("%d %d\n", j, (j - (j - i - 1) / 2));
                    i = j;
                    left = i + 1;
                    countL++;
                    break;
                }
            }
            if (countL == 0) for (int k = i; k < str.size(); ++k) status[k] = 1;
        }
    }

    for (int i = 0; i < str.size(); ++i)
    {
        printf("%c", (status[i] == 0)?'.':(status[i] > 0)?'R':'L');
    }

    return 0;
}