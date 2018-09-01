#include <cstdio>

void PrintNumber(char* str)
{
	int len = 0;
	int idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] != '0') break;
		++idx;
	}
	while (str[idx] != '\0')
	{
		printf("%c", str[idx]);
		++idx;
		++len;
	}
	if (len == 0) printf("%c", '0');
	printf("\n");
}

void Print1ToMaxOfDigitsCore(int n, char* str, int curr)
{
	if (curr == n)
	{
		PrintNumber(str);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		str[curr] = '0' + i;
		Print1ToMaxOfDigitsCore(n, str, curr + 1);
	}
}

void Print1ToMaxOfDigits(int n)
{
	if (n <= 0) return;

	char* str = new char[n + 1];
	str[n] = '\0';

	Print1ToMaxOfDigitsCore(n, str, 0);

	delete[] str;
}

int main()
{
	Print1ToMaxOfDigits(2);
}