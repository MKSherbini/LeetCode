#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class RemoveAllAdjacentDuplicatesInString
{
public:
	// 12 ms, faster than 98.62% : 10.8 MB, less than 74.37%
	string solution(string s) {
		int n = size(s);
		int i = 0;

		string ans;

		while (i < n) {
			Printer::print(i, ans);
			if (!ans.empty() &&
				s[i] == ans.back())
				ans.pop_back();
			else
				ans.push_back(s[i]);
			i++;
		}

		return ans;
	}
	vector<string> output = {
		"ca",
		"ay"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"abbaca",
		"azxxzy"
	};
};