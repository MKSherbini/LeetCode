#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class MaximumNestingDepthOfTheParentheses
{
public:
	// 0 ms, faster than 100% : 7.3 MB, less than 96.47%
	int solution(string s) {
		int mx = 0, cnt = 0;
		for (auto c : s) {
			if (c == '(') cnt++;
			else if (c == ')') cnt--;
			mx = max(mx, cnt);
		}

		return mx;
	}
	vector<int> output = {
		3,
		3
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"(1+(2*3)+((8)/4))+1",
		"(1)+((2))+(((3)))"
	};
};