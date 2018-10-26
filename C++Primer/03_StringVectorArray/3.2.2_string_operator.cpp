#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

void string_io()
{
	freopen("data/string_io.txt", "r", stdin);
	string s;
	while (cin >> s)
		cout << s << ": " << s.size() << " ";
	cout << endl;
	fclose(stdin);
}

void string_getline()
{
	freopen("data/string_io.txt", "r", stdin);
	string s;
	while (getline(cin, s))
		cout << s << ": " << s.size() << " ";
	cout << endl;
	fclose(stdin);
}

void string_cmp()
{
    string str = "Hello";
    string phrase = "Hello World";
    string slang  = "Hiya";

    if (str < phrase) cout << "str is smaller" << endl;		// str is smaller
    if (slang > str) cout << "slang is greater" << endl;	// slang is greater
    if (slang > phrase) cout << "slang is greater" << endl; // slang is greater
}

int main()
{
	string_io();		// Hello: 5 World!: 6
	string_getline();	//     Hello World!    : 20
	string_cmp();
	return 0;
}