#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reverse-words-in-a-string/

class ReverseWordsInAString
{
public:
	// 0 ms, faster than 100% : 7 MB, less than 89.31%
	string solution(string s) {
		string ans;
		int n = size(s);
		for (int i = n - 1; i >= 0; i--) {
			int j = i;
			while (j >= 0 && s[j] != ' ')
				--j;
			for (int k = j + 1; k <= i; k++)
				ans.push_back(s[k]);
			if (j < i)
				ans.push_back(' ');
			i = j;
		}

		if (ans.back() == ' ') ans.pop_back();

		return ans;
	}
	vector<string> output = {
		"blue is sky the",
		"world hello",
		"example good a"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"the sky is blue",
		"  hello world  ",
		"a good   example"
	};
};