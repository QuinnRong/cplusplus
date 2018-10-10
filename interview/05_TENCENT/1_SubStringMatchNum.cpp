#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_set>

using namespace std;

bool NaiveMatcher(string& A, string& B, int idx)
{
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] != B[idx + i]) return false;
	}
	return true;
}

int NaiveCount(unordered_set<string>& substrings, string& str, int k)
{	/*
	time: O(m*n*k)
	*/
	int res = 0;
	for (auto substring : substrings)
	{
		for (int i = 0; i <= str.size() - k; ++i)
		{
			if (NaiveMatcher(substring, str, i))
			{
				++res;
				break;
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
			++count; break;
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

int KMPCount(unordered_set<string>& substrings, string& str, int k)
{	/*
	time: O(m*n)
	*/
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

int DPCount(const string& X, const string& Y, int k)
{	/*
	time: O(m*n)
	space: O(m*n)
	*/
	int** c = new int*[X.size() + 1];
	for (int i = 0; i <= X.size(); ++i) c[i] = new int[Y.size() + 1];

	for (int i = 0; i <= X.size(); ++i) c[i][0] = 0;
	for (int j = 0; j <= Y.size(); ++j) c[0][j] = 0;

	unordered_set<string> substrings;
	for (int i = 1; i <= X.size(); ++i)
	{
		for (int j = 1; j <= Y.size(); ++j)
		{
			if (X[i - 1] == Y[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = 0;
			if (c[i][j] >= k)
			{
				// cout << X.substr(i - k, k) << endl;
				substrings.insert(X.substr(i - k, k));
			}
			// cout << c[i][j] << " ";
		}
		// cout << endl;
	}

	for (auto p : substrings) cout << p << " ";
	cout << endl;

	delete[] c;
	return substrings.size();
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

	unordered_set<string> substrings;
	for (int i = 0; i <= A.size() - k; ++i)
	{
		substrings.insert(A.substr(i, k));
	}

	// for (auto i : substrings) cout << i << endl;

	cout << NaiveCount(substrings, B, k) << endl;
	cout << KMPCount(substrings, B, k) << endl;
	cout << DPCount(A, B, k) << endl;
}