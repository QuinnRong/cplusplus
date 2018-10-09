#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> split(const string& str)
{    /*
    input: 4.8.4
    output: vector<int> v = {4,8,4};
    */
    vector<int> res;
    int start = 0;
    int tmp;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            tmp = stoi(str.substr(start, i - start));
            res.push_back(tmp);
            start = i + 1;
        }
    }
    tmp = stoi(str.substr(start, str.size() - start));
    res.push_back(tmp);
    return res;
}

bool compare(const string& a, const string& b)
{   /*
    input: 4.8 4.8.4
    output: true (4.8 < 4.8.4)
    input: 4.8 2.96
    output: false (4.8 >= 2.96)
    */
    vector<int> v1 = split(a);
    vector<int> v2 = split(b);

    int size = ((v1.size() < v2.size()) ? v1.size() : v2.size());

    bool isEqual = true;
    for (int i = 0; i < size; ++i)
    {
        if (isEqual && v1[i] > v2[i]) return false;
        if (v1[i] < v2[i]) isEqual = false;
    }
    if (isEqual && v1.size() > v2.size()) return false;
    else return true;
}

int main()
{
    freopen("5.txt", "r", stdin);
    int n;
    cin >> n;

    vector<string> data;
    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        data.push_back(str);
    }
    
    sort(data.begin(), data.end(), compare);    // sort by version number form old to new

    for (auto i : data)
        cout << i << endl;

    fclose(stdin);
    return 0;
}