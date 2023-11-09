#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-number-of-homogenous-substrings/?envType=daily-question&envId=2023-11-09

class CountNumberOfHomogenousSubstrings
{
public:
	// 18 ms, faster than 97.17% : 11.9 MB, less than 94.78%
	int solution(string s) {
		int n = size(s);
		const int MOD = 1e9 + 7;
		long long ans = 0;
		for (size_t i = 0; i < n; i++) {
			size_t j = i + 1;
			while (j < n && s[j] == s[i]) {
				j++;
			}
			size_t f = j - i;
			ans += f * (f + 1) / 2;
			ans %= MOD;
			i = j - 1;
		}

		return ans;
	}
	vector<int> output = {
		13,
		2,
		15
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"abbcccaa",
		"xy",
		"zzzzz"
	};
};