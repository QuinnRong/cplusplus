#include <cstdio>
#include <vector>

using namespace std;

void PermulationCore(char* pStr, char* pBegin)
{
	if (*pBegin == '\0') printf("%s\n", pStr);

	for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
	{
		char tmp = *pCh;
		*pCh = *pBegin;
		*pBegin = tmp;

		PermulationCore(pStr, pBegin + 1);

		tmp = *pCh;
		*pCh = *pBegin;
		*pBegin = tmp;
	}
}

void Permulation(char* str)
{
	if (str == nullptr) return;
	PermulationCore(str, str);
}

void CombinationCore(char* str, int curr, int m, vector<char>& charVector)
{
	if (charVector.size() == m)
	{
		for (const auto& ch : charVector) printf("%c ", ch);
			printf("\n");
		return;
	}
	if (str[curr] == '\0') return;

	charVector.push_back(str[curr]);
	CombinationCore(str, curr + 1, m, charVector);
	charVector.pop_back();

	CombinationCore(str, curr + 1, m, charVector);
}

void Combination(char* str, int m)
{
	if (str == nullptr) return;
	vector<char> charVector;
	CombinationCore(str, 0, m, charVector);
}

int main()
{
	char str[] = "abcd";
	Permulation(str);
	Combination(str, 2);
}