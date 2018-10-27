#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include "iterator_binary_search.h"

using namespace std;

int main()
{
	freopen("data/binary_search.txt", "r", stdin);
	int len;
	cin >> len;
	vector<int> v(len);
	for (int i = 0; i < len; ++i)
		cin >> v[i];

	for (auto i : v)
		cout << i << " ";
	cout << endl;

	int sought;
	while (cin >> sought)
	{
		int res = *binary_search(v, sought);
		if (res == sought)
			cout << sought << " --> true" << endl;
		else
			cout << sought << " --> false" << endl;
	}

	fclose(stdin);
	return 0;
}

/**
 * result:
 * 1 2 3 4 5
 * 3 --> true
 * 6 --> false
 */