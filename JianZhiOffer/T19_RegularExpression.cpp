#include <cstdio>

bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' || *pattern == '\0')
		return *str == *pattern;

	if (*(pattern + 1) == '*')
	{
		if (*str == *pattern)
			return matchCore(str, pattern + 2) ||
					matchCore(str + 1, pattern);
		else
			return matchCore(str, pattern + 2);
	}

	if (*pattern == '.' || *str == *pattern)
		return matchCore(str + 1, pattern + 1);

	return false;
}

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr) return false;
	return matchCore(str, pattern);
}

int main()
{
	char str[] = "aaa";
	char pattern1[] = "a.a";		// match
	printf("%s and %7s %s\n", str, pattern1, match(str, pattern1)?"match":"dismatch");
	char pattern2[] = "ab*ac*a";	// match
	printf("%s and %7s %s\n", str, pattern2, match(str, pattern2)?"match":"dismatch");
	char pattern3[] = "ab*a";		// dismatch
	printf("%s and %7s %s\n", str, pattern3, match(str, pattern3)?"match":"dismatch");
}