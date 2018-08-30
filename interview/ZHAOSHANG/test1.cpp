#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    freopen("1.in","r",stdin);

    bool* wall = new bool[10000000];
    memset(wall, 0, 10000000 * sizeof(bool));

    int n;
    cin >> n;

    int* poster = new int[n * 2];

    for(int i = 0; i < n; ++i){
        scanf("%d %d", &poster[i * 2], &poster[i * 2 + 1]);
        // cout << poster[i * 2] << poster[i * 2 + 1] << endl;
    }

    int count = 0;
    for(int i = n - 1; i >= 0; --i){
        int num = 0;
        for (int j = poster[i * 2]; j <= poster[i * 2 + 1]; ++j)
        {
            if (!wall[j])
            {
                wall[j] = true;
                num += 1;
            }
        }
        if (num > 0) count++;
    }
    // for (int i = 0; i <= 10; ++i)
    // {
    //  printf("%s\n", wall[i]?"1":"0");
    // }
    cout << count << endl;
    return 0;
}