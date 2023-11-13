#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sort-vowels-in-a-string/

class SortVowelsInAString
{
public:
	// 46 ms, faster than 34.28% : 11.9 MB, less than 94.53%
	string solution(string s) {
		string bad = "aeiouAEIOU";
		string vowels;
		for (auto c : s) {
			if (bad.find(c) == -1) continue;
			vowels.push_back(c);
		}
		sort(begin(vowels), end(vowels), greater());
		for (auto& c : s) {
			if (bad.find(c) == -1) continue;
			c = vowels.back();
			vowels.pop_back();
		}
		return s;
	}
	vector<string> output = {
		"lEOtcede",
		"lYmpH"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"lEetcOde",
		"lYmpH"
	};
};