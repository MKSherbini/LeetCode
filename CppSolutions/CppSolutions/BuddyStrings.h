#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/buddy-strings/

class BuddyStrings
{
public:
	// 0 ms, faster than 100% : 6.8 MB, less than 99.57%
	bool solution(string s, string goal) {
		if (size(s) != size(goal)) return false;
		int n = size(s);
		int last = -1;
		vector<int> f(26);
		bool duplicate = 0;
		for (size_t i = 0; i < n; i++) {
			if (f[s[i] - 'a']++) duplicate = 1;
			if (s[i] != goal[i])
				if (last == -1)
					last = i;
				else if (last >= 0 && s[last] == goal[i] && s[i] == goal[last])
					last = -2;
				else {
					last = -3;
					break;
				}
		}
		return last == -2 || (last == -1 && duplicate);
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"ab",
		"ab",
		"aa"
	};
	vector<string> input2 = {
		"ba",
		"ab",
		"aa"
	};
};