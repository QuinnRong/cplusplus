#include <iostream>

using namespace std;

// overloaded functions
int sum (int a, int b)
{
    return a - b;
}

double sum (double a, double b)
{
    return a - b;
}

// function template
template <class T>
T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}

int main ()
{
    cout << sum (10,20) << '\n';            // -10
    cout << sum (1.0,1.5) << '\n';          // -0.5
    cout << sum<int> (10,20) << '\n';       // 30
    cout << sum<double> (1.0,1.5) << '\n';  // 2.5
    return 0;
}