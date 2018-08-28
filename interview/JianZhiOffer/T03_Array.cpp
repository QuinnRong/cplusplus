#include <cstdio>

bool duplicate1(int* array, int len, int* res)
{   /*
    time: O(n)
    space: O(n)
    */
    if (array == nullptr || len <= 0) return false;
    int* hash = new int[len];
    for (int i = 0; i < len; ++i) hash[i] = 0;
    for (int i = 0; i < len; ++i)
    {
        if (array[i] < 0 || array[i] > len - 1) return false;
        hash[array[i]] += 1;
    }
    for (int i = 0; i < len; ++i)
    {
        if (hash[i] > 1)
        {
            *res = i;
            delete[] hash;
            return true;
        }
    }
    delete[] hash;
    return false;
}

bool duplicate2(int* array, int len, int* res)
{   /*
    time: O(n)
    space: O(1)
    */
    if (array == nullptr || len <= 0) return false;
    for (int i = 0; i < len; ++i)
        if (array[i] < 0 || array[i] > len - 1) return false;
    for (int i = 0; i < len; ++i)
    {
        while (array[i] != i)
        {
            if (array[array[i]] == array[i])
            {
                *res = array[i];
                return true;
            }
            else
            {
                int temp = array[array[i]];
                array[array[i]] = array[i];
                array[i] = temp;
            }
        }
    }
    return false;
}

int countRange(const int* array, int len, int start, int end)
{
    int res = 0;
    for (int i = 0; i < len; ++i)
        if (array[i] >= start && array[i] <= end) ++res;
    return res;
}

int getDuplication(const int* array, int len)
{   /*
    array: 1~len-1, must exist duplication
    requirement: does not change the array
    time: O(nlogn)
    space: O(1)
    */
    if (array == nullptr || len <= 0) return -1;
    for (int i = 0; i < len; ++i)
        if (array[i] < 1 || array[i] > len - 1) return -1;
    int start = 1;
    int end = len - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);
        int count = countRange(array, len, start, mid);
        if (start == end)
        {
            if (count > 1) return start;
            else return -1;
        }
        if (count > (mid - start + 1)) end = mid;
        else start = mid + 1;
    }
    return -1;
}

int main()
{
    int array[] = {2,3,1,0,2,5,3};
    int res;
    if (duplicate1(array, sizeof(array)/sizeof(array[0]), &res))
        printf("duplication exists: %d\n", res);
    else
        printf("%s\n", "duplication not exists");
    
    if (duplicate2(array, sizeof(array)/sizeof(array[0]), &res))
        printf("duplication exists: %d\n", res);
    else
        printf("%s\n", "duplication not exists");

    int array1[] = {2,3,5,4,3,2,6,7};
    res = getDuplication(array, sizeof(array)/sizeof(array[0]));
    if (res <= 0)
        printf("%s\n", "illegal array");
    else
        printf("duplication contains: %d\n", res);

    res = getDuplication(array1, sizeof(array)/sizeof(array[0]));
    if (res <= 0)
        printf("%s\n", "illegal array");
    else
        printf("duplication contains: %d\n", res);
}