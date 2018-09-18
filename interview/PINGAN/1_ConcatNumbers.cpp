#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &str1, const string str2)
{
    string tmp1 = str1 + str2;
    string tmp2 = str2 + str1;
    return (tmp1 < tmp2);
}

void PrintMinNumber(int* numbers, int length)
{
    if (numbers == nullptr || length <= 0) return;

    vector<string> strVec;
    for (int i = 0; i < length; ++i)
        strVec.push_back(to_string(numbers[i]));
    // for (auto i : strVec)
    //  cout << i << endl;

    sort(strVec.begin(), strVec.end(), compare);

    for (auto item : strVec)
        cout << item;
    cout << endl;
}

int main()
{
    freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    // cout << n << endl;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    PrintMinNumber(arr, n);

    delete[] arr;
    fclose(stdin);
    return 0;
}