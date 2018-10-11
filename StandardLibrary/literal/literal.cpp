#include <cstdio>

int main()
{
	printf("0x7fffffff = %d\n", 0x7fffffff);
	printf("0x80000000 = %d\n", 0x80000000);
	printf("0xffffffff = %d\n", 0xffffffff);
	printf("0x00000000 = %d\n", 0x00000000);
}

/*
result:
0x7fffffff = 2147483647
0x80000000 = -2147483648
0xffffffff = -1
0x00000000 = 0
*/