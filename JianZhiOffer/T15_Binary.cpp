#include <cstdio>

void printBinary(const int& n)
{
	printf("%d:\n", n);
	unsigned int flag = 1;
	flag = flag << 31;
	while (flag)
	{
		printf("%c", (n & flag)?'1':'0');
		flag = flag >> 1;
	}
	printf("\n");
}

int NumberOf1(const int& n)
{
	int count = 0;
	int flag = n;
	while (flag)
	{
		++count;
		flag = flag & (flag - 1);
	}
	return count;
}

int main()
{
	int n = -10;
	printBinary(n);	printf("number of 1 = %d\n", NumberOf1(n));
	n = n >> 1;
	printBinary(n);	printf("number of 1 = %d\n", NumberOf1(n));
	n = 10;
	printBinary(n);	printf("number of 1 = %d\n", NumberOf1(n));
	n = n >> 1;
	printBinary(n);	printf("number of 1 = %d\n", NumberOf1(n));
}