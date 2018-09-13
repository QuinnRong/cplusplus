#include <cstdio>
#include <stdexcept>

char FindNotRepeatingChar(const char *str)
{
	if (str == nullptr) throw std::runtime_error("Invalid Params!");

	int position[256];
	for (int i = 0; i < 256; ++i)
		position[i] = -1;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (position[str[i] - 'a'] == -1)
			position[str[i] - 'a'] = i;
		else if (position[str[i] - 'a'] >= 0)
			position[str[i] - 'a'] = -2;
	}

	int idx = 256;
	for (int i = 0; i < 256; ++i)
		if (position[i] > 0 && position[i] < idx)
			idx = position[i];

	if (idx == 256)
	{
		printf("No such character!\n");
		return '\0';
	}
	else
		return ('a' + idx);
}

int main()
{
	char str[] = "abaccdeff";
	printf("%c\n", FindNotRepeatingChar(str));
}