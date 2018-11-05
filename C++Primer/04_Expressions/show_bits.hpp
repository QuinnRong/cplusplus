#ifndef SHOW_BITS_HPP
#define SHOW_BITS_HPP

#include <cstdio>	/* printf, sprintf */
#include <cstdlib>	/* exit */

typedef unsigned char *byte_pointer;

const char hex_map[16][5] = {"0000","0001","0010","0011",
							 "0100","0101","0110","0111",
							 "1000","1001","1010","1011",
							 "1100","1101","1110","1111"};

char* hex2bits(char c)
{
	if (c >= '0' && c <= '9')
		return (char*) hex_map[c - '0'];
	else if (c >= 'a' && c <= 'f')
		return (char*) hex_map[c - 'a' + 10];
	else
		printf("invalid hex character\n");
	exit(-1);
}

void show_bits(byte_pointer start, size_t len)
{
	char str[256];
	size_t i;
	for (i = 0; i < len; ++i)
		sprintf(str + 2 * i, "%.2x", start[i]);	// or %02x
	// printf("%s\n", str);

	char *iter = str;
	while (*iter != '\0')
	{
		printf("%c%c: %s%s\n", *iter, *(iter + 1), hex2bits(*iter), hex2bits(*(iter + 1)));
		++iter;
		++iter;
	}
}

template <typename T>
void show_bits(T x)
{
	show_bits((byte_pointer) &x, sizeof(T));
}

#endif