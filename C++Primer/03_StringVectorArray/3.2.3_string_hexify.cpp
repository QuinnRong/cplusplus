#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	const string hexdigits = "0123456789ABCDEF";
	freopen("data/string_hexify.txt", "r", stdin);
	string result;
	string::size_type n;
	while (cin >> n)
		if (n < hexdigits.size())
			cout << n << " -> " << hexdigits[n] << endl;
	fclose(stdin);
	return 0;
}

/**
 * result
 * 12 -> C
 * 0 -> 0
 * 5 -> 5
 * 15 -> F
 * 8 -> 8
 * 15 -> F
 */