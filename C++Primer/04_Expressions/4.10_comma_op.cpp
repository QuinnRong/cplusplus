#include <vector>
#include <iostream>

using namespace std;

void front()
{
	vector<int> ivec = {0, 0, 0, 0, 0};
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;
	cout << "cnt=" << cnt;
	cout << endl;
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;
}

void back()
{
	vector<int> ivec = {0, 0, 0, 0, 0};
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
		ivec[ix] = cnt;
	cout << "cnt=" << cnt;
	cout << endl;
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;
}

int main()
{
	front();
	back();
}