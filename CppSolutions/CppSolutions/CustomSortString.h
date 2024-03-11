#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/custom-sort-string/

class CustomSortString
{
public:
	// 0 ms, faster than 100% : 7.4 MB, less than 78.2%
public:
	string solution(string order, string s) {
		vector<int> f(26);
		for (auto c : s) f[c - 'a']++;

		string ans;
		for (auto c : order) ans += string(f[c - 'a'], c), f[c - 'a'] = 0;
		for (size_t i = 0; i < 26; i++) {
			if (f[i]) ans += string(f[i], i + 'a');
		}

		return ans;
	}
	vector<string> output = {
		"cbad",
		"bcad"
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"cba",
		"bcafg"
	};
	vector<string> input2 = {
		"abcd",
		"abcd"
	};
};