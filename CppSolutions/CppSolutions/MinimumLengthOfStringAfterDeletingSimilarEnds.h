#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

class MinimumLengthOfStringAfterDeletingSimilarEnds
{
public:
	// 19 ms, faster than 96.9% : 13.7 MB, less than 81.03%
	int solution(string s) {
		int i = 0, j = size(s) - 1;

		while (i < j) {
			if (s[i] != s[j]) break;

			char c = s[i];
			while (i <= j && s[i] == c) {
				i++;
			}
			while (i <= j && s[j] == c) {
				j--;
			}
		}

		return j - i + 1;
	}
	vector<int> output = {
		2,
		0,
		3
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"ca",
		"cabaabac",
		"aabccabba"
	};
};