#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/repeated-substring-pattern/

class RepeatedSubstringPattern
{
public:
	// 8 ms, faster than 98.48% : 14.1 MB, less than 41.3%
	bool solution(string s) {
		int n = size(s);

		for (int sz = n / 2; sz >= 1; sz--) {
			if (n % sz) continue;
			bool bad = false;
			string s1 = s.substr(0, sz);
			for (size_t i = sz; i < n; i += sz) {
				if (s1 != s.substr(i, sz)) {
					bad = true;
					break;
				}
			}

			if (!bad) return true;
		}

		return false;
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"abab",
		"aba",
		"abcabcabcabc"
	};
};