#include <cstdio>

bool matchCore(char* str, char* pattern, int idS, int idP)
{
	if (str[idS] == '\0' || pattern[idP] == '\0') return str[idS] == pattern[idP];

	if (pattern[idP + 1] == '*')
	{
		if (str[idS] != pattern[idP])
		{
			return matchCore(str, pattern, idS, idP + 2);
		}
		else
		{
			return matchCore(str, pattern, idS, idP + 2) ||
					matchCore(str, pattern, idS + 1, idP);
		}
	}
	else if (pattern[idP] == '.' || str[idS] == pattern[idP])
	{
		return matchCore(str, pattern, idS + 1, idP + 1);
	}
	else
	{
		return false;
	}
}

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr) return false;
	return matchCore(str, pattern, 0, 0);
}

int main()
{
	char str[] = "aaa";
	char pattern1[] = "a.a"; printf("%s\n", match(str, pattern1)?"match":"dismatch");
	char pattern2[] = "ab*ac*a"; printf("%s\n", match(str, pattern2)?"match":"dismatch");
	char pattern3[] = "ab*a"; printf("%s\n", match(str, pattern3)?"match":"dismatch");
}