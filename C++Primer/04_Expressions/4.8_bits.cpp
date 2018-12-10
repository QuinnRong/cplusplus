#include <cstdio>

#include "show_bits.hpp"

int main()
{
	unsigned char bits = 0233;
	printf("\nbits:\n"); show_bits(bits);			// 10011011
	printf("\nbits << 8:\n"); show_bits(bits << 8); // 00000000 10011011 00000000 00000000
	printf("\n~bits:\n"); show_bits(~bits);			// 01100100 11111111 11111111 11111111

	unsigned char b1 = 0145;	// 01100101
	unsigned char b2 = 0257;	// 10101111
	printf("\nb1 & b2:\n"); show_bits(b1 & b2);		// 00100101 00000000 00000000 00000000
	printf("\nb1 | b2:\n"); show_bits(b1 | b2);		// 11101111 00000000 00000000 00000000
	printf("\nb1 ^ b2:\n"); show_bits(b1 ^ b2);		// 11001010 00000000 00000000 00000000

								// 'q' 01110001
	printf("\n~'q'<<6:\n");	show_bits(~'q'<<6); 	// 10000000 11100011 11111111 11111111
}