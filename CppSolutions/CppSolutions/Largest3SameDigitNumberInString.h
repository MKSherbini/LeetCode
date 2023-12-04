#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/largest-3-same-digit-number-in-string/

class Largest3SameDigitNumberInString
{
public:
	// 0 ms, faster than 100% : 6.7 MB, less than 91.88%
	string solution(string num) {
		int n = size(num);
		char c = -1;
		for (size_t i = 2; i < n; i++) {
			if (num[i] == num[i - 1] && num[i] == num[i - 2]) c = max(c, num[i]);
		}

		return c == -1 ? "" : string(3, c);
	}
	vector<string> output = {
		"777",
		"000",
		""
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"6777133339",
		"2300019",
		"42352338"
	};
};