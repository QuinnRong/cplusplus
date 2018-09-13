#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int FindSubStr(const string &str, int length)
{
    int hash[256];
    memset(hash, -1, 256*sizeof(int));
    int begin = -1, res = 0;
    for (int i = 0; i < length; ++i)
    {
        if (hash[str[i]] > begin) begin = hash[str[i]];
        if ((i - begin) > res) res = i - begin;
        hash[str[i]] = i;
    }
    return res;
}

int main(){
    freopen("1.in","r",stdin);
    string str;
    cin >> str;
    cout << FindSubStr(str, str.size()) << endl;
    return 0;
}