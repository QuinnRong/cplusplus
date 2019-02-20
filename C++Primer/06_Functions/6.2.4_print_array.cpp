#include <iostream>

using std::cout; using std::endl; using std::begin; using std::end;

void print(const int i)
{
    cout << i << endl;
}

void print(const int *arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << " ";
    }
    cout << endl;
}

void print(const int(&arr)[2])
{
    // cout << sizeof(arr) << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void print(const int(*arr)[2])
{
    // cout << sizeof(*arr) << endl;
    for (auto i : *arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print(i);
    print(j, end(j) - begin(j));
    print(begin(j), end(j));
    print(j);
    print(&j);
}