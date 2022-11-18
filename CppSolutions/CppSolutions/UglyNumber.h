#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/ugly-number/

class UglyNumber
{
public:
	// 0 ms, faster than 100% : 5.7 MB, less than 86.56%
	bool solution(int n) {
		if (n <= 0) return 0;
		while (n > 1) {
			if (n % 2 == 0)
				n /= 2;
			else if (n % 3 == 0)
				n /= 3;
			else if (n % 5 == 0)
				n /= 5;
			else
				return 0;
		}
		return 1;
	}
	vector<int> output = {
		true,
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		6,
		1,
		14
	};
};