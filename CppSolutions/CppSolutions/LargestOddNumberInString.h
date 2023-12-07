#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/largest-odd-number-in-string/

class LargestOddNumberInString
{
public:
	// 23 ms, faster than 91.89% : 14.1 MB, less than 93.87%
	string solution(string num) {
		while (!empty(num) && num.back() % 2 == 0) {
			num.pop_back();
		}
		return num;
	}
	vector<string> output = {
		"5",
		"",
		"35427"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"52",
		"4206",
		"35427"
	};
};