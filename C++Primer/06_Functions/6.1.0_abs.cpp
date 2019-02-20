#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

int abs(int i)
{   /*
    INT_MIN < i <= INT_MAX
    */
    return i > 0 ? i : -i;
}

void interactive_abs()
{
    const string prompt = "Enter an integer:\n";
    const string out_of_range = "Out of range, please try again.\n";
    for (long long i; cout << prompt, cin >> i;)
    {
        if (i > INT_MIN && i <= INT_MAX)
        {
            cout << abs(i) << endl;
        }
        else
        {
            cout << out_of_range;
        } 
    }
}

int main()
{
    cout << "INT_MAX = " << INT_MAX << endl; // cout << ((1 << 31) - 1) << endl;
    cout << "INT_MIN = " << INT_MIN << endl; // cout << (1 << 31) << endl;
    interactive_abs();
    return 0;
}