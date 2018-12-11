#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl;

bool is_prefix(const vector<int>& lhs, const vector<int>& rhs)
{
	if (lhs.size() > rhs.size())
		return is_prefix(rhs, lhs);
	for (int i = 0; i < lhs.size(); ++i)
		if (lhs[i] != rhs[i]) return false;
	return true;
}

int main()
{
	vector<int> ivec1{0,1,1,2};
	vector<int> ivec2{0,1,1,2,3,5,8};
	cout << (is_prefix(ivec2, ivec1) ? "yes" : "no") << endl;
}