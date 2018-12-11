#include <iostream>
#include <string>
using std::string; using std::cin; using std::cout; using std::endl;

int main()
{
	string scores[] = {"F","D","C","B","A","A++"};
	for (unsigned g; cin >> g; )
	{
		string lettergrade;

		// if (g < 60)
		// {
		// 	lettergrade = scores[0];
		// }
		// else
		// {
		// 	lettergrade = scores[(g - 50) / 10];
		// 	if (g != 100)
		// 	{
		// 		lettergrade += g % 10 > 7 ? "+" : g % 10 < 3 ? "-" : "";
		// 	}
		// }

		lettergrade = g < 60 ? scores[0] : scores[(g - 50) / 10];
		lettergrade += g < 60 || g == 100 ? "" : g % 10 > 7 ? "+" : g % 10 < 3 ? "-" : "";

		cout << lettergrade << endl;
	}
}