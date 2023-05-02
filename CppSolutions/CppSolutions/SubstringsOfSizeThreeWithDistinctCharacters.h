#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class SubstringsOfSizeThreeWithDistinctCharacters
{
public:
	// 0 ms, faster than 100% : 6.1 MB, less than 96.18%
	int solution(string s) {
		int n = size(s);
		if (n < 3) return 0;
		int ans = 0;
		for (int i = 0; i <= n - 3; i++) {
			if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
				ans++;
		}

		return ans;
	}
	vector<int> output = {
		1,
		4
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"xyzzaz",
		"aababcabc"
	};
};