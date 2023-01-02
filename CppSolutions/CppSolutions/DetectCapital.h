#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/detect-capital/

class DetectCapital
{
public:
	// 0 ms, faster than 100% : 6 MB, less than 70.49%
	bool solution(string word) {
		int c = 0;
		int n = size(word);
		for (int i = 0; i < n; i++)
			if (isupper(word[i]))
				c++;
		return n == c || c == 1 && isupper(word[0]) || c == 0;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"USA",
		"FlaG"
	};
};