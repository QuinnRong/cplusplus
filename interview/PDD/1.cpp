#include <string>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs)
{  
    return rhs.second < lhs.second;  
}

int main()
{
    freopen("1.txt", "r", stdin);
    string str;
    map<string, int> wordFreq;
    while (cin >> str)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        while (str.back() < 'a' || str.back() > 'z')
            str = str.substr(0, str.size() - 1);
        if (wordFreq.find(str) == wordFreq.end())
            wordFreq.insert({str, 1});
        else
            ++wordFreq[str];
    }

    vector<PAIR> wordVector(wordFreq.begin(), wordFreq.end());
    sort(wordVector.begin(), wordVector.end(), cmp_by_value);

    int max = wordVector[0].second;

    vector<string> res;
    for (auto i : wordVector)
    {
        if (i.second == max)
        {
            res.push_back(i.first);
        }
        else
        {
            break;
        }
    }

    sort(res.begin(), res.end());
    for (auto i : res)
        cout << i << " ";
    cout << endl;

    fclose(stdin);
    return 0;
}