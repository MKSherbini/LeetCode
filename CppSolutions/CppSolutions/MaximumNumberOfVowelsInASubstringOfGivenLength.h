#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class MaximumNumberOfVowelsInASubstringOfGivenLength
{
public:
	// 27 ms, faster than 36.25% : 9.9 MB, less than 95.7%
	int solution(string s, int k) {
		int n = size(s);
		int i = 0;
		const string aeiou = "aeiou";
		int mx = 0, cur = 0;
		for (size_t j = 0; j < n; j++) {
			if (aeiou.find(s[j]) != -1) cur++;
			if (j >= k&& aeiou.find(s[i++]) != -1) cur--;
			mx = max(mx, cur);
		}

		return mx;
	}
	vector<int> output = {
		3,
		2,
		2
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abciiidef",
		"aeiou",
		"leetcode"
	};
	vector<int> input2 = {
		3,
		2,
		3
	};
};