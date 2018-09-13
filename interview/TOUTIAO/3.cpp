#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool isPartIP(const string &str, int start, int end)
{
    if (start < 0 || start > end || end >= str.size()) return false;
    if (str[start] == '0' || end - start > 1) return false;
    if (end == start || end - start == 1) return true;
    if (end - start == 2)
    {
        int tmp = (str[start] - '0')*100 + (str[start + 1] - '0')*10 + str[start + 2] - '0';
        if (tmp <= 255) return true;
    }
    return false;
}

int numIP(const string &str, int start, int dotNum)
{
    if (start > str.size() - 1) return 0;
    if (dotNum == 0) return (isPartIP(str, start, str.size() - 1)?1:0);
    int res = 0;
    res += numIP(str, start + 1, dotNum - 1);
    res += numIP(str, start + 2, dotNum - 1);
    if (isPartIP(str, start, start + 2))
        res += numIP(str, start + 3, dotNum - 1);
    return res;
}

int main(){
    freopen("3.in","r",stdin);
    string str;
    cin >> str;
    cout << str << endl;
    cout << numIP(str, 0, 3);
    return 0;
}