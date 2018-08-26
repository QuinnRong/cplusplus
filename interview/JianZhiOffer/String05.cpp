#include <cstdio>

void ReplaceBlank(char* str, int len)
{
	if (str == nullptr || len <= 0) return;

	int originalLength = 0, numOfBlank = 0;
	while (str[originalLength] != '\0')
	{
		if (str[originalLength] == ' ') ++numOfBlank;
		++originalLength;
	}

	int newLength = originalLength + 2 * numOfBlank;
	if (newLength > len) return;
	for (int i = originalLength - 1; i >= 0; --i)
	{
		if (i == newLength - 1) break;
		if (str[i] == ' ')
		{
			str[--newLength] = '0';
			str[--newLength] = '2';
			str[--newLength] = '%';
		}
		else str[--newLength] = str[i];
	}
}

int main()
{
	char str[] = "We are happy.";
	ReplaceBlank(str, 100);
	printf("%s\n", str);
}