#include <cstdio>
#include <vector>

using namespace std;

int NumCases = 0;
int AllCases = 0;

bool isAlligned(const char* pStr)
{
	while (*pStr != '\0')
	{
		const char* pCurr = pStr + 1;
		while (*pCurr != '\0')
		{
			if ((pCurr - pStr) == (*pCurr - *pStr) || (pCurr - pStr) == - (*pCurr - *pStr))
				return true;
			++pCurr;
		}
		++pStr;
	}
	return false;
}

void PermulationCore(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		if (!isAlligned(pStr))
		{
			++NumCases;
			printf("%s\n", pStr);
		}
		++AllCases;
	}

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

int main()
{
	char strChess[] = "12345678";
	Permulation(strChess);
	printf("All cases = %d, valid cases = %d\n", AllCases, NumCases);
}