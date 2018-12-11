#include <iostream>
#include <string>
#include <stdexcept>
using std::string; using std::cin; using std::cout; using std::endl; using std::runtime_error;

int main()
{
	for (int ival1, ival2; cin >> ival1 >> ival2; )
	{
		try
		{
			if (ival2 == 0)
				throw std::runtime_error("divisor is zero");
			cout << ival1 / ival2 << endl;
			break;
		}
		catch (std::runtime_error err)
		{
			cout << err.what() << endl;
			cout << "Try again? Enter yes or no: ";
			string s;
			cin >> s;
			if (!cin || tolower(s[0] == 'n'))
				break;
		}
	}
	return 0;
}