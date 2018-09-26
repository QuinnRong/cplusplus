#include <string>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void ComputeSumCore(vector<int>& prices, int id, vector<vector<int>>& coupon, vector<bool>& isUsed, int& sum, int& min)
{
    if (id >= prices.size())
    {
        if (sum < min) min = sum;
        return;
    }

    vector<int> choices;
    for (int i = 0; i < coupon.size(); ++i)
    {
        if (!isUsed[i] && coupon[i][0] <= prices[id])
            choices.push_back(i);
        else
            break;
    }

    sum += prices[id];

    for (auto c : choices)
    {
        sum -= coupon[c][1];
        isUsed[c] = true;
        ComputeSumCore(prices, id + 1, coupon, isUsed, sum, min);
        sum += coupon[c][1];
        isUsed[c] = false;
    }
    ComputeSumCore(prices, id + 1, coupon, isUsed, sum, min);
    sum -= prices[id];
}

int ComputeSum(vector<int>& prices, vector<vector<int>>& coupon)
{
    int min = 0x7fffffff;
    int sum = 0;
    vector<bool> isUsed;
    for (int i = 0; i < coupon.size(); ++i)
        isUsed.push_back(false);
    ComputeSumCore(prices, 0, coupon, isUsed, sum, min);
    return min;
}

bool cmp_by_key(const vector<int>& lhs, const vector<int>& rhs)
{  
    return lhs[0] < rhs[0];  
}

int main()
{
    freopen("3.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<int> prices;
    int price;
    for (int i = 0; i < n; ++i)
    {
        cin >> price;
        prices.push_back(price);
    }

    vector<vector<int>> coupon;
    int a, b;
    for (int j = 0; j < m; ++j)
    {
        cin >> a >> b;
        coupon.push_back({a, b});
    }

    sort(coupon.begin(), coupon.end(), cmp_by_key);

    // for (auto i : coupon)
    //     cout << i[0] << " " << i[1] << endl;

    cout << ComputeSum(prices, coupon) << endl;

    fclose(stdin);
    return 0;
}