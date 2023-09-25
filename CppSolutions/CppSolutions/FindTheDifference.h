#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-difference/

class FindTheDifference
{
public:
	// 0 ms, faster than 100% : 6.9 MB, less than 25.22%
	char solution(string s, string t) {
		vector<int> f(26);

		for (auto c : s)
			f[c - 'a']++;

		for (auto c : t)
			if (--f[c - 'a'] < 0) {
				return c;
			}

		return -1;
	}
	vector<char> output = {
		'e',
		'y'
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abcd",
		""
	};
	vector<string> input2 = {
		"abcde",
		"y"
	};
};