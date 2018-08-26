#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int diff = 'a' - 'A';
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= diff;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += diff;
        }
    }
    cout << str << endl;
}