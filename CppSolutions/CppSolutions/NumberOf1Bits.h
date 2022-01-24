#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-1-bits/

class NumberOf1Bits
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 96.69%
	int solution(uint32_t n) {
		int cnt = 0;
		while (n)
			cnt += n & 1, n >>= 1;
		return cnt;
	}
	vector<int> output = {
		3,
		1,
		31,
	};
	vector<uint32_t> input1 = {
		0b00000000000000000000000000001011,
		0b00000000000000000000000010000000,
		0b11111111111111111111111111111101,
	};
};

