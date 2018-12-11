#include <iostream>
using std::string; using std::cin; using std::cout; using std::endl;

int main()
{
	unsigned cnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
	char c, cpre = '\0';
	while (cin >> std::noskipws >> c)
	{
		switch(c)
		{
			case 'a': case 'e': case 'o': case 'u':
				++cnt;
				break;
			case '\t':
				++tabCnt;
				break;
			case '\n':
				++newLineCnt;
				break;
			case 'f':
				if (cpre == 'f') ++ffCnt;
				break;
			case 'l':
				if (cpre == 'f') ++flCnt;
				break;
			case 'i':
				++cnt;
				if (cpre == 'f') ++fiCnt;
				break;
		}
		cpre = c;
	}
	cout << cnt << endl;
	cout << tabCnt << endl;
	cout << newLineCnt << endl;
	cout << ffCnt << endl;
	cout << flCnt << endl;
	cout << fiCnt << endl;
}