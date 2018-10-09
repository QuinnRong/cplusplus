#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

double KLDivergence(unordered_map<int, pair<int, int>>& data, int num1, int num2)
{   /*
    input:
        map: key, <frequency1, frequency2>
        num1: sum of frequency1
        num2: sum of frequency2
    output:
        KL = sum(p * log2(p/q))
    */
    double res = 0;
    for (auto item : data)
    {
        if (item.second.second == 0)
        {
            cout << "q can not be zero!" << endl;
            return -1;
        }
        double p = item.second.first * 1.0 / num1;
        double q = item.second.second * 1.0 / num2;
        res += p * log2(p / q);
    }
    return res;
}

int main()
{
    unordered_map<int, pair<int, int>> data;
    
    freopen("1.txt", "r", stdin);
    string line;
    int tmp;

    getline(cin, line);
    istringstream iss(line);
    int num1 = 0;
    while (iss >> tmp)
    {
        if (data.find(tmp) == data.end())
        {
            data[tmp].first = 0;
            data[tmp].second = 0;
        }
        ++data[tmp].first;
        ++num1;
    }

    getline(cin, line);
    iss = istringstream(line);
    int num2 = 0;
    while (iss >> tmp)
    {
        if (data.find(tmp) == data.end())
        {
            data[tmp].first = 0;
            data[tmp].second = 0;
        }
        ++data[tmp].second;
        ++num2;
    }

    // for (auto p : data)
    // {
    //  cout << p.first << ": " << p.second.first << " " << p.second.second << endl;
    // }

    double res = KLDivergence(data, num1, num2);

    // 四折五入保留两位小数输出
    int ans = (res + 0.005) * 100;
    res = ans / 100.0;
    printf("%.2f\n", res);

    fclose(stdin);
    return 0;
}
