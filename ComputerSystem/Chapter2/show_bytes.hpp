#ifndef SHOW_BYTES_H
#define SHOW_BYTES_H

#include <cstdio>
#include <cstdlib>	/* size_t */

typedef unsigned char *byte_pointer;

void show_ascii(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0; i < len; ++i)
		printf(" %.2d", start[i]);
	printf("\n");
}

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

#endif
