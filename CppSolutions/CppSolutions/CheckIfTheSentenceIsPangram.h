#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class CheckIfTheSentenceIsPangram
{
public:
	// 0 ms, faster than 100% : 6.2 MB, less than 98.63%
	bool solution(string sentence) {
		vector<char> f(26, 0);

		for (auto c : sentence)
			f[c - 'a'] = 1;

		for (auto x : f)
			if (x != 1) return false;

		return true;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"thequickbrownfoxjumpsoverthelazydog",
		"leetcode"
	};
};