#include <cstdio>

bool isNumber(const char chr)
{
	if (chr >= '0' && chr <= '9') return true;
	return false;
}

bool isNumbericFraction(const char* str)
{
	if (isNumber(str[0]))
	{
		++str;
		while (isNumber(str[0])) ++str;
	}
	if (str[0] == '\0') return true;
	else if (str[0] == 'e' || str[0] == 'E')
	{
		++str;
		if (str[0] == '+' || str[0] == '-') ++str;
		while (str[0] != '\0')
		{
			if (!isNumber(str[0])) return false;
			++str;
		}
		return true;
	}
	else return false;
}

bool isNumericUnsigned(const char* str)
{
	if (str[0] == '.')
	{
		if (!isNumber(str[1])) return false;
		return isNumbericFraction(str + 1);
	}
	if (isNumber(str[0]))
	{
		++str;
		while (isNumber(str[0])) ++str;
		if (str[0] == '.') return isNumbericFraction(str + 1);
		else return isNumbericFraction(str);
	}
}

bool isNumeric(const char* str)
{
	if (str == nullptr) return false;
	if (str[0] == '+' || str[0] == '-') ++str;
	return isNumericUnsigned(str);
}

int main()
{
	char* myStr[] = {"+100", "123.45e+6", "12e+5.4"};
	for (int i = 0; i < 3; ++i) printf("%s\n", isNumeric(myStr[i])?"yes":"no");
}