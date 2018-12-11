#include <iostream>
#include <string>
using std::string; using std::cin; using std::cout; using std::endl;

int main()
{
	string rsp;
	do
	{
		cout << "please enter two strings: ";
		string s1, s2;
		cin >> s1 >> s2;
		cout << (s1.size() < s2.size() ? s1 : s2) << " is shorter\n\n";
		cout << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && tolower(rsp[0]) != 'n');
}