#include <iostream>
using std::cout; using std::endl;

#include <iterator>
using std::begin; using std::end;

using int_3 = int[3];
typedef double coord[3];

int main()
{
	int a[3] = {};
	for (auto i : a)
		cout << i << " ";	// 0 0 0
	cout << endl;

	int b[3][2] = {1};
	for (auto &r : b)		// int (&r)[2] = b[0];
	{
		for (auto i : r)
			cout << i << " ";	// 1 0 ; 0 0 ; 0 0 ;
		cout << "; ";
	}
	cout << endl;

	for (auto r = b; r != b + 3; ++r)
	{
		for (auto i = *r; i != *r + 2; ++i)
			cout << *i << " ";
		cout << "; ";
	}
	cout << endl;

	for (int (*r)[2] = b; r != b + 3; ++r)
	{
		for (int *i = *r; i != *r + 2; ++i)
			cout << *i << " ";
		cout << "; ";
	}
	cout << endl;

	for (auto r = begin(b); r != end(b); ++r)
	{
		for (auto i = begin(*r); i != end(*r); ++i)
			cout << *i << " ";
		cout << "; ";
	}
	cout << endl;

	coord x{0.1, 0.2, 0.3};
	for (auto v : x)
		cout << v << " ";		// 0.1 0.2 0.3
	cout << endl;

	return 0;
}