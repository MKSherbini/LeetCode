#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class MinimumNumberOfStepsToMakeTwoStringsAnagram
{
public:
	// 42 ms, faster than 94.43% : 16.8 MB, less than 97.67%
	int solution(string s, string t) {
		int n = size(s);
		vector<int> f(26);
		for (size_t i = 0; i < n; i++) {
			f[s[i] - 'a']++;
			f[t[i] - 'a']--;
		}

		int ans = 0;
		for (auto x : f) {
			if (x > 0) ans += x;
		}

		return ans;
	}
	vector<int> output = {
		1,
		5,
		0
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"bab",
		"leetcode",
		"anagram"
	};
	vector<string> input2 = {
		"aba",
		"practice",
		"mangaar"
	};
};