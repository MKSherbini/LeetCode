#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/determine-if-string-halves-are-alike/

class DetermineIfStringHalvesAreAlike
{
public:
	// 0 ms, faster than 100% : 6.6 MB, less than 56.35%
	bool solution(string s) {
		set<int> ss = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
		const int n = size(s) / 2;
		int v = 0, v2 = 0;

		for (size_t i = 0; i < n; i++) {
			if (ss.count(s[i]))
				++v;
			if (ss.count(s[i + n]))
				++v2;
		}

		return v == v2;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"book",
		"textbook"
	};
};