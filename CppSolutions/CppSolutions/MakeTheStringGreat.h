#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/make-the-string-great/

class MakeTheStringGreat
{
public:
	// 0 ms, faster than 100% : 6 MB, less than 97.68%
	string solution(string s) {
		int n = size(s);
		int i = 0;

		string ans;

		while (i < n) {
			Printer::print(i, ans);
			if (!ans.empty() &&
				tolower(s[i]) == tolower(ans.back()) &&
				s[i] != ans.back())
				ans.pop_back();
			else
				ans.push_back(s[i]);
			i++;
		}

		return ans;
	}

	// 3 ms, faster than 82.74% : 6.9 MB, less than 22.08%
	string solution2(string s) {
		int n = size(s);
		int i = 0;

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