#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/break-a-palindrome/

class BreakAPalindrome
{
public:
	// 0 ms, faster than 100% : 6 MB, less than 95.35%
	string solution(string palindrome) {
		int n = size(palindrome);
		if (n == 1) return "";

		for (size_t i = 0; i < n >> 1; i++)
		{
			if (palindrome[i] != 'a') {
				palindrome[i] = 'a';
				return palindrome;
			}
		}

		palindrome[n - 1] = 'b';
		return palindrome;
	}
	vector<string> output = {
		"aaccba",
		""
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"abccba",
		"a"
	};
};