#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/power-of-four/

class PowerOfFour
{
public:
	// 0 ms, faster than 100% : 5.7 MB, less than 88.37%
	bool solution(int n) {
		if (n <= 0) return 0;
		int zeros = 0;
		while (n) {
			if (n & 1 && n >> 1) return false;
			zeros += !(n & 1);
			n >>= 1;
		}

		return !(zeros & 1);
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		16,
		5,
		1
	};
};