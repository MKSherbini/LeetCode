#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/determine-if-two-strings-are-close/

class DetermineIfTwoStringsAreClose
{
public:
	// 187 ms, faster than 66.47% : 20.6 MB, less than 64.37%
	bool solution(string word1, string word2) {
		vector<int> f1(26, 0), f2(26, 0);
		set<char> s1, s2;

		for (auto c : word1)
			++f1[c - 'a'], s1.insert(c);
		for (auto c : word2)
			++f2[c - 'a'], s2.insert(c);

		sort(begin(f1), end(f1));
		sort(begin(f2), end(f2));
		
		return s1 == s2 && f1 == f2;
	}

	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abc",
		"a",
		"cabbba"
	};
	vector<string> input2 = {
		"bca",
		"aa",
		"abbccc"
	};
};