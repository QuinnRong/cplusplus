#include <cstdio>

int LongestSubString(char *str)
{
	if (str == nullptr) return 0;
	int position[26];
	for (int i = 0; i < 26; ++i)
		position[i] = -1;

	int start = -1;
	int res = 0;
	int max = 0;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (position[str[i] - 'a'] != -1 && position[str[i] - 'a'] > start)
		{
			start = position[str[i] - 'a'];
		}
		position[str[i] - 'a'] = i;
		res = i - start;
		if (res > max) max = res;

		// printf("%d %d %d\n", start, res, max);
		// for (int i = 0; i < 26; ++i)
		// 	printf("%d ", position[i]);
		// printf("\n");
	}
	return max;
}

int main()
{
	char str[] = "arabcacfr";
	printf("%d\n", sizeof(str));
	printf("%d\n", LongestSubString(str));
}