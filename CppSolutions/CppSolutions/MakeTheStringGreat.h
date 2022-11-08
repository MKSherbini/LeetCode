#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/make-the-string-great/

class MakeTheStringGreat
{
public:
	// 3 ms, faster than 82.74% : 6.9 MB, less than 22.08%
	string solution(string s) {
		int n = size(s);
		int i = 0, j = 1;

		while (i < n - 1) {
			Printer::print(i, s);
			if (tolower(s[i]) == tolower(s[i + 1]) && s[i] != s[i + 1])
				s = s.substr(0, i) + s.substr(i + 2), n -= 2, i = max(0, i - 1);
			else
				i++;
		}
		return s;
	}

	vector<string> output = {
		"leetcode",
		"",
		"s"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"leEeetcode",
		"abBAcC",
		"s"
	};
};