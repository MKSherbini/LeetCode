#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reverse-words-in-a-string/

class ValidPalindrome
{
public:
	// 0 ms, faster than 100% : 7.2 MB, less than 90.9%
	bool solution(string s) {
		int i = 0, j = size(s) - 1;

		while (i < j) {
			while (i < j && !isalnum(s[i])) i++;
			if (i >= j) break;
			while (i < j && !isalnum(s[j])) j--;
			if (i >= j) break;
			if (tolower(s[i]) != tolower(s[j])) return false;
			++i, --j;
		}

		return true;
	}

	// 0 ms, faster than 100% : 7.5 MB, less than 49.82%
	bool solution2(string s) {
		string t = "";
		for (int i = 0; i < s.size(); i++)
			if (isalnum(s[i]))
				t += tolower(s[i]);
		int n = size(t);
		for (int i = 0; i < n / 2; i++)
			if (t[i] != t[n - i - 1])
				return false;
		return true;
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"A man, a plan, a canal: Panama",
		"race a car",
		" "
	};
};