#include <iostream>
#include <string>
using std::cout; using std::endl; using std::string; using std::cin;

#include "Factorial.h"

int max_fact()
{
    int i = 1;
    for (int res = 1, prev = 1; res / prev == i;)
    {
        prev = res;
        res *= ++i;
        // cout << i << " " << res << endl;
    }
    --i;
    return i;
}

int fact(int i)
{   /*
    1 <= i <= 12
    */
    return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact()
{
    const string prompt = "Enter a number within [1, 12]:\n";
    const string out_of_range = "Out of range, please try again.\n";
    for (int i; cout << prompt, cin >> i;)
    {
        if (i < 1 || i > 12)
        {
            cout << out_of_range;
        }
        else
        {
            cout << fact(i) << endl;
        }
    }
}
