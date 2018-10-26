#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cctype>
using std::ispunct; using std::toupper;

void string_punctuation()
{
	string s("Hello World!!!");
	decltype(s.size()) punct_cnt = 0;
	for (auto c : s)
		if (ispunct(c)) ++punct_cnt;
	cout << punct_cnt << " punctuation characters in " << s << endl;
}

void string_upper()
{
	string s("Hello World!!!");
	for (auto &c : s)
		c = toupper(c);
	cout << s << endl;
}

void string_upper_first_char()
{
	string s("some string");
	if (!s.empty())
		s[0] = toupper(s[0]);
	cout << s << endl;
}

void string_upper_first_word()
{
	string s("some string");
	for (decltype(s.size()) index = 0; index < s.size() && !isspace(s[index]); ++index)
		s[index] = toupper(s[index]);
	cout << s << endl;
}

int main()
{
	string_punctuation();		// 3 punctuation characters in Hello World!!!
	string_upper();				// HELLO WORLD!!!
	string_upper_first_char(); 	// Some string
	string_upper_first_word();  // SOME string
	return 0;
}