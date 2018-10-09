#include <iostream>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

bool NaiveMatcher(string& A, string& B, int idx)
{
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] != B[idx + i]) return false;
	}
	return true;
}

int NaiveCount(set<string>& substrings, string& str, int k)
{
	int res = 0;
	for (auto substring : substrings)
	{
		for (int i = 0; i <= str.size() - k; ++i)
		{
			if (NaiveMatcher(substring, str, i))
			{
				++res;
			}
		}
	}
	return res;
}

int KMPMatcher(const string& T, const string& P, int* pi)
{
	int count = 0;
	int q = 0;		// num of characters matched
	for (int i = 0; i < T.size(); ++i)
	{
		while (q > 0 && T[i] != P[q])
			q = pi[q - 1];	// if some characters are matched and the next character does not
		if (T[i] == P[q])
			++q;			// if next character matches
		if (q == P.size())
		{
			++count;
			q = pi[q - 1];	// if pattern matches
		}
	}
	return count;
}

void PrefixFun(const string& P, int* pi)
{
	int q = 0;		// num of characters matched
	pi[0] = 0;		// if only one character matches(and next character does not), next move must be zero
	for (int i = 1; i < P.size(); ++i)
	{
		while (q > 0 && P[i] != P[q])
			q = pi[q - 1];	// if some characters are matched and the next character does not
		if (P[i] == P[q])
			++q;			// if next character matches
		pi[i] = q;			// remain num of characters matched is stored
	}
}

int KMPCount(set<string>& substrings, string& str, int k)
{
	int res = 0;
	int* pi = new int[k];
	for (auto pattern : substrings)
	{
		PrefixFun(pattern, pi);
		res += KMPMatcher(str, pattern, pi);
	}
	delete[] pi;
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

	// for (auto i : substrings) cout << i << endl;

	cout << NaiveCount(substrings, B, k) << endl;
	cout << KMPCount(substrings, B, k) << endl;
}