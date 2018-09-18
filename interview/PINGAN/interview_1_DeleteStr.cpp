#include <cstdio>

void Swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

char* DeleteStr(char* T, char* P)
{	/*
	requirement of space: O(1)
	time: O(mn)
	*/
	if (P == nullptr || T == nullptr) return T;

	int end = 0;
	bool del = false;	// whether to delete the char
	for (int i = 0; T[i] != '\0'; ++i)
	{
		del = false;
		for (int j = 0; P[j] != '\0'; ++j)
		{
			if (T[i] == P[j])
			{
				del = true;
				break;
			}
		}
		if (del == false)
		{
			if (end != i) Swap(&T[i], &T[end]);
			++end;
		}
	}
	T[end] = '\0';
	return T;
}

int main()
{
	char str1[] = "I love SJTU.";
	char str2[] = "SU";
	printf("%s\n", DeleteStr(str1, str2));	// "I love JT."
}