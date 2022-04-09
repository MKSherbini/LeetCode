#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class LetterCombinationsOfAPhoneNumber
{
public:
	// 0 ms, faster than 100% : 6.6 MB, less than 59.62%
	vector<string> solution(string digits) {
		if (digits.size() == 0) return {};
		map<char, vector<char>> lettersMap;
		for (size_t i = 2; i <= 6; i++)
			for (size_t j = (i - 2) * 3; j < (i - 2) * 3 + 3; j++)
				lettersMap[i + '0'].push_back(j + 'a');
		for (size_t j = 15; j < 19; j++)
			lettersMap[7 + '0'].push_back(j + 'a');
		for (size_t j = 19; j < 22; j++)
			lettersMap[8 + '0'].push_back(j + 'a');
		for (size_t j = 22; j < 26; j++)
			lettersMap[9 + '0'].push_back(j + 'a');

		vector<string> ans;
		curse(ans, digits, lettersMap, "", 0);
		return ans;
	}

	void curse(vector<string>& ans, string& digits, map<char, vector<char>>& lettersMap, string tmp, int i) {
		if (tmp.size() == digits.size()) return ans.push_back(tmp);
		else if (i == digits.size()) return;

		curse(ans, digits, lettersMap, tmp, i + 1);
		for (auto c : lettersMap[digits[i]])
			curse(ans, digits, lettersMap, tmp + c, i + 1);
	}

	vector<vector<string>> output = {
		{"ad","ae","af","bd","be","bf","cd","ce","cf"},
		{},
		{"a","b","c"}
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"23",
		"",
		"2"
	};
};