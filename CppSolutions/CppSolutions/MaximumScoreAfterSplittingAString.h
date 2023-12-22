#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-score-after-splitting-a-string/

class MaximumScoreAfterSplittingAString
{
public:
	// 0 ms, faster than 100% : 6.5 MB, less than 87.5%
	int solution(string s) {
		int zeros = 0, ones = 0;
		for (auto c : s)
			if (c == '1') ones++;

		int ans = 0;
		for (size_t i = 0; i < size(s) - 1; i++) {
			zeros += s[i] == '0';
			ones -= s[i] == '1';
			ans = max(ans, zeros + ones);
		}

		return ans;
	}
	vector<int> output = {
		5,
		5,
		3
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"011101",
		"00111",
		"1111"
	};
};