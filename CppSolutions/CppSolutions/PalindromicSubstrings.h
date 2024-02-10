#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/palindromic-substrings/

class PalindromicSubstrings
{
public:
	// 0 ms, faster than 100% : 7.4 MB, less than 78.58%
	int solution(string s) {
		int n = size(s);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int c = 1;
			for (int l = i - 1, r = i + 1; l >= 0 && r < n; l--, r++) {
				if (s[l] != s[r]) break;
				c++;
			}
			for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) {
				if (s[l] != s[r]) break;
				c++;
			}
			ans += c;
		}

		return ans;
	}
	vector<int> output = {
		3,
		6
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"abc",
		"aaa"
	};
};