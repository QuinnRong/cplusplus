#include <iostream>
using std::cout; using std::endl; using std::cin;

void swap(int *lhs, int *rhs)
{
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int main()
{
    for (int lhs, rhs; cout << "Enter two number:\n", cin >> lhs >> rhs;)
    {
        swap(&lhs, &rhs);
        cout << lhs << " " << rhs << endl;
    }
}