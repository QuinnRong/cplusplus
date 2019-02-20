#include <iostream>
using std::cout; using std::endl;

void reset(int *ip)
{
    *ip = 0;
    ip = 0;
}

void reset(int &ir)
{
    ir = 0;
}

int main()
{
    int i = 1;
    reset(&i);
    cout << i << endl;
    i = 1;
    reset(i);
    cout << i << endl;
}