#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	string s1;
	cout << s1 << endl;
	string s2("hiya");
	cout << s2 << endl;
	string s3(s2);
	cout << s3 << endl;
	string s4 = "hiya";
	cout << s4 << endl;
	string s5 = s4;
	cout << s5 << endl;
	string s6(4, 'c');
	cout << s6 << endl;
	string s7 = string(4, 'c');
	cout << s7 << endl;
	return 0;
}

/**
 * result:
 * 
 * hiya
 * hiya
 * hiya
 * hiya
 * cccc
 * cccc
 */