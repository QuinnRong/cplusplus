#include <cstdio>
#include <string>

int TranslationCountCore(const std::string &str, int *count, int idx)
{
	if (idx < 0) return 1;
	else if (idx == 0) 
	{
		count[idx] = 1;
		return 1;
	}
	else
	{
		count[idx] = TranslationCountCore(str, count, idx - 1);
		int twoChar = (str[idx - 1] - '0') * 10 + (str[idx] - '0');
		if (twoChar >= 10 && twoChar <=25)
			count[idx] += TranslationCountCore(str, count, idx - 2);
		return count[idx];
	}
}

int TranslationCount(int number)
{
	if (number < 0) return 0;
	std::string str = std::to_string(number);
	int *count = new int[str.size()];
	int res = TranslationCountCore(str, count, str.size() - 1);
	delete[] count;
	return res;
}

int main()
{
	int number = 12258;
	int res = TranslationCount(number);
	printf("%d\n", res);
}