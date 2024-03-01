#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-odd-binary-number/

class MaximumOddBinaryNumber
{
public:
	// 0 ms, faster than 100% : 8.1 MB, less than 68.48%
	string solution(string s) {
		int n = size(s);
		int ones = count_if(begin(s), end(s), [](char c) {return c == '1'; }) - 1;

		s[n - 1] = '1';
		for (size_t i = 0; i < n - 1; i++) {
			s[i] = i < ones ? '1' : '0';
		}

		return s;
	}
	vector<string> output = {
		"001",
		"1001"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"010",
		"0101"
	};
};