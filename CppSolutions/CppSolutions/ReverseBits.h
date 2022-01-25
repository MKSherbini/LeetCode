#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reverse-bits/

class ReverseBits
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 96.64%
	uint32_t solution(uint32_t n) {
		n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}

	// 0 ms, faster than 100% : 5.8 MB, less than 81.22%
	uint32_t solution3(uint32_t n) {
		for (int i = 0; i < 16; i++)
			n = (n & ~(1 << i) & ~(1 << (31 - i)))
			| (((n & (1 << i)) >> i) << (31 - i))
			| (((n & (1 << (31 - i))) >> (31 - i) << i));
		return n;
	}

	uint32_t solution2(uint32_t n) {
		for (int i = 0; i < 16; i++)
		{
			uint32_t ai = 1 << i;
			uint32_t a = (n & ai);
			uint32_t bi = 1 << (31 - i);
			uint32_t b = (n & bi);

			n &= ~ai & ~bi;
			n |= a ? bi : 0;
			n |= b ? ai : 0;
		}
		return n;
	}
	vector<uint32_t> output = {
		0b00111001011110000010100101000000,
		0b10111111111111111111111111111111,
	};
	vector<uint32_t> input1 = {
		0b00000010100101000001111010011100,
		0b11111111111111111111111111111101,

	};
};

