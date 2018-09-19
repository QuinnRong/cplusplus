#include <cstdio>
#include <string>

using namespace std;

void KMPMatcher(const string& T, const string& P, int* pi)
{	/*
	time: O(T.size())
	*/
	int q = 0;		// num of characters matched
	for (int i = 0; i < T.size(); ++i)
	{
		while (q > 0 && T[i] != P[q])
			q = pi[q - 1];	// if some characters are matched and the next character does not
		if (T[i] == P[q])
			++q;			// if next character matches
		if (q == P.size())
		{
			printf("Pattern occurs with shift %d\n", i - P.size() + 1);
			q = pi[q - 1];	// if pattern matches
		}
	}
}

void PrefixFun(const string& P, int* pi)
{	/*
	time: O(P.size())
	pi[q - 1] = pi(q) = max{k: k < q && Pk is suffix of Pq} 
	where Pn means prefix of P with n characters, and the goal is to
	find largest prefix that are true suffix of currently matched part of patterns.
	*/
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

int main()
{
	string P = "ababaca";
	string T = "abababacaba";

	int* pi = new int[P.size()];
	PrefixFun(P, pi);
	// int pi[] = {0,0,1,2,3,0,1};

	KMPMatcher(T, P, pi);

	delete[] pi;
	return 0;
}

/*
Pattern occurs with shift 2
*/