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

void QuickSort(int* array, int left, int right)
{
    if (left >= right) return;
    int idx = PartSort1(array, left, right);
    QuickSort(array, left, idx - 1);
    QuickSort(array, idx + 1, right);
}

int main()
{
    int array[] = {4,1,7,6,9,2,8,0,3,5};
    QuickSort(array, 0, sizeof(array)/sizeof(array[0]) - 1);
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}