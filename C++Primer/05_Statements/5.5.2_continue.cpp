#include <iostream>
#include <string>
using std::string; using std::cin; using std::cout; using std::endl;

int main()
{
	string s, spre;
	while (cin >> s)
	{
		if (!isupper(s[0]))
		{
			spre = "";
			continue;
		}
		if (s == spre) break;
		spre = s;
	}
	cout << (cin ? s : "no duplicated strings") << endl;
}