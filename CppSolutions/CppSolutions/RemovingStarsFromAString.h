#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/removing-stars-from-a-string/

class RemovingStarsFromAString
{
public:
	// 67 ms, faster than 96.67% : 24.8 MB, less than 93.33%
	string solution(string s) {
		string ans;
		int del = 0;
		for (int i = size(s) - 1; i >= 0; i--) {
			if (s[i] == '*') del++;
			else if (del) del--;
			else ans += s[i];
		}

		reverse(begin(ans), end(ans));
		return ans;
	}
	vector<string> output = {
		"lecoe",
		""
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"leet**cod*e",
		"erase*****"
	};
};