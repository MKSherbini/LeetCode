#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/valid-anagram/

class ValidAnagram
{
public:
	// 0 ms, faster than 100% : 7.2 MB, less than 78.6%
	bool solution(string s, string t) {
		int c[26] = { 0 };
		for (size_t i = 0; i < s.size(); i++)
			c[s[i] - 'a']++;
		for (size_t i = 0; i < t.size(); i++)
			c[t[i] - 'a']--;
		for (size_t i = 0; i < 26; i++)
			if (c[i] != 0) return false;
		return true;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"anagram",
		"rat"
	};
	vector<string> input2 = {
		"nagaram",
		"car"
	};
};