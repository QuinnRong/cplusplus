#include <cstdio>

#include "show_bits.hpp"

int main()
{
	unsigned char bits = 0233;
	printf("\nbits:\n"); show_bits(bits);			// 10011011
	printf("\nbits << 8:\n"); show_bits(bits << 8); // 00000000 00000000 10011011 00000000
	printf("\n~bits:\n"); show_bits(~bits);			// 11111111 11111111 11111111 01100100

	unsigned char b1 = 0145;	// 01100101
	unsigned char b2 = 0257;	// 10101111
	printf("\nb1 & b2:\n"); show_bits(b1 & b2);		// 00000000 00000000 00000000 00100101
	printf("\nb1 | b2:\n"); show_bits(b1 | b2);		// 00000000 00000000 00000000 11101111
	printf("\nb1 ^ b2:\n"); show_bits(b1 ^ b2);		// 00000000 00000000 00000000 11001010
}