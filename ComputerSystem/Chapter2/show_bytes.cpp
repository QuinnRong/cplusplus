#include <cstdio>
#include <cstring>
#include <cstdlib>	/* size_t */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0; i < len; ++i)
		printf(" %.2x", start[i]);	// or %02x
	printf("\n");
}

template <typename T>
void show_bytes(T x)
{
	show_bytes((byte_pointer) &x, sizeof(T));
}

void show_ascii(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0; i < len; ++i)
		printf(" %.2d", start[i]);
	printf("\n");
}

int main()
{
	show_bytes(12345);			// 39 30 00 00
	show_bytes(float(12345.0));	// 00 e4 40 46
	show_bytes(12345.0);		// 00 00 00 00 80 1c c8 40

	show_bytes(nullptr);		// 00 00 00 00
	int a = 0;
	int *p = &a;
	show_bytes(p);				// 28 ff 61 00
	show_bytes(&a);				// 28 ff 61 00

	char str[256] = "01234 ABCDE abcde";
	show_bytes((byte_pointer)str, strlen(str));	// 30 31 32 33 34 20 41 42 43 44 45 20 61 62 63 64 65
	show_ascii((byte_pointer)str, strlen(str)); // 48 49 50 51 52 32 65 66 67 68 69 32 97 98 99 100 101

	return 0;
}