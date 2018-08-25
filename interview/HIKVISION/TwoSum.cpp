#include <iostream>

using namespace std;

int TwoSum(int* array, int len, int target)
{   /*
    input: an sorted array of ints, target value
    output: num of int pairs that sum up to the arget value
    */
    int min = array[0];
    if (min < 0)
    {
        for (int i = 0; i < len; ++i) array[i] -= min;
        target -= 2* min;
    }

    if (array[0] > target) return 0;
    int res = 0;
    int start = 0, end = len - 1;
    int sum;
    while (start < end)
    {
        sum = array[start] + array[end];
        if (sum > target) --end;
        else if (sum < target) ++start;
        else
        {
            --end;
            ++start;
            ++res;
        }
    }
    return res;
}

int main()
{
    int array[4] = {-3,-2,-2,-1};
    cout << TwoSum(array, 4, -4) << endl;
    int array1[4] = {1,2,2,3};
    cout << TwoSum(array1, 4, 4) << endl;
}