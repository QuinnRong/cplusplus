#include <iostream>

using namespace std;

int PartSort1(int* array, int left, int right)
{
    int val = array[right];
    while (left < right)
    {
        while (left < right && array[left] <= val) ++left;
        array[right] = array[left];
        while (left < right && array[right] >= val) --right;
        array[left] = array[right];
    }
    array[right] = val;
    return right;
}

void HalfSort(int* array, int left, int right, int target)
{
    if (left >= right) return;
    int idx = PartSort1(array, left, right);
    if (idx == target) return;
    else if (idx > target) HalfSort(array, left, idx - 1, target);
    else HalfSort(array, idx + 1, right, target);
}

int kLargest(int* array, int left, int right, int k)
{
    int target = right + 1 - k;
    if (target > right || target < 0) return -1;
    HalfSort(array, left, right, target);
    return array[target];
}

int main()
{
    int array[] = {4,1,7,6,9,2,8,0,3,5};
    cout << kLargest(array, 0, sizeof(array)/sizeof(array[0]) - 1, 3) << endl;
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}