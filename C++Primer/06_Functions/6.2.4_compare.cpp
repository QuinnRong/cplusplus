#include <iostream>

using namespace std;

bool compare(const int i, const int *ip)
{
    return (i > *ip);
}

int main()
{
    for (int a, b; cout << "Enter two number:\n", cin >> a >> b;)
    {
        cout << (compare(a, &b) ? a : b) << endl;
    }
}