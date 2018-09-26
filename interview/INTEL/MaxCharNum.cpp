#include <cstdio>
#include <cstring>

int MaxCharNum(const char* str)
{	/*
	input: a string
	output: max num of characters (case insensitive)
	*/
	if (str == nullptr) return 0;

	int hash[26];
	for (int i = 0; i < 26; ++i) hash[i] = 0;

	// char* tmp = str;	// !!! invalid conversion from const char* to char*

	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] - 'a' >= 0 && str[i] - 'z' <= 0) ++hash[str[i] - 'a'];
		if (str[i] - 'A' >= 0 && str[i] - 'Z' <= 0) ++hash[str[i] - 'A'];
		++i;
	}

	int res = 0;
	for (int i = 0; i < 26; ++i)
		if (hash[i] > res) res = hash[i];

	return res;
}

int main()
{
	printf("%d\n", MaxCharNum("I like IT"));	// 3
}