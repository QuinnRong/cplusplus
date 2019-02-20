#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

bool isContainUpper(const string &str)
{
    for (auto ch : str)
    {
        if (isupper(ch)) return true;
    }
    return false;
}

void toLower(string &str)
{
    for (auto &ch : str)
    {
        ch = tolower(ch);
    }
}

int main()
{
    for (string str; cout << "Enter a string:\n", cin >> str;)
    {
        if (isContainUpper(str))
        {
            toLower(str);
            cout << "Lower string: " << str << endl;
        }
        else
        {
            cout << "No upper letter." << endl;
        }
    }
}