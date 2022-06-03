#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/first-unique-character-in-a-string/

class FirstUniqueCharacterInAString
{
public:
	//
	int solution(string s) {
		int frq[26] = { 0 };
		for (auto c : s)
			frq[c - 'a']++;
		for (size_t i = 0; i < s.size(); i++)
			if (frq[s[i] - 'a'] == 1) return i;
		return -1;
	}
	vector<int> output = {
		0,
		2,
		-1
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"leetcode",
		"loveleetcode",
		"aabb"
	};
};