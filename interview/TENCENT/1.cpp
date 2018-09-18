#include <iostream>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

bool isSubstring(string& A, string& B, int idx)
{
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] != B[idx + i]) return false;
	}
	return true;
}

int countSubstring(set<string>& substrings, string& str, int k)
{
	int res = 0;
	for (auto substring : substrings)
	{
		for (int i = 0; i <= str.size() - k; ++i)
		{
			if (isSubstring(substring, str, i))
			{
				cout << i << endl;
				++res;
			}
		}
	}
	return res;
}

int main()
{
	freopen("1.txt", "r", stdin);
	int k;
	cin >> k;
	string A;
	string B;
	cin >> A >> B;
	// cout << A << endl; cout << B << endl;

	set<string> substrings;
	for (int i = 0; i <= A.size() - k; ++i)
	{
		substrings.insert(A.substr(i, k));
	}

	for (auto i : substrings) cout << i << endl;

	cout << countSubstring(substrings, B, k) << endl;
}