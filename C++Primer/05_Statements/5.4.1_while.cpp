#include <iostream>
#include <string>
using std::string; using std::cin; using std::cout; using std::endl; using std::pair;

int main()
{
	pair<string, int> max_duplicated;
	int cnt = 0;
	for (string str, strpre; cin >> str; strpre = str)
	{
		if (str == strpre) ++cnt;
		else cnt = 0;
		if (cnt > max_duplicated.second)
			max_duplicated = {str, cnt};
	}
	if (max_duplicated.second)
		cout << max_duplicated.first << " occurs " << max_duplicated.second + 1 << " times" << endl;
	else 
		cout << "no continuous words" << endl;
}