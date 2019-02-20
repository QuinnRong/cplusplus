#include <iostream>

using namespace std;

void swap_ip(int *&lhs, int *&rhs)
{
    int *temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main()
{
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    swap_ip(pa, pb);
    cout << a << " " << b << endl;
    cout << *pa << " " << *pb << endl;
}