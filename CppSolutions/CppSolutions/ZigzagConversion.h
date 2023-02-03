#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/zigzag-conversion/

class ZigzagConversion
{
public:
	// 3 ms, faster than 98.89% : 10.5 MB, less than 53.57%
	string solution(string s, int numRows) {
		vector<string> rows(numRows);

		int r = 0, dir = 1;
		for (size_t i = 0; i < size(s); i++) {
			rows[r] += s[i];
			if (r == numRows - 1 && dir == 1) dir = -1;
			else if (r == 0 && dir == -1)dir = 1;
			r += dir;
		}
		string ans;
		for (auto& r : rows)
			ans += r;

		return ans;
	}
	vector<string> output = {
		"PAHNAPLSIIGYIR",
		"PINALSIGYAHRPI",
		"A"
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"PAYPALISHIRING",
		"PAYPALISHIRING",
		"A"
	};
	vector<int> input2 = {
		3,
		4,
		1
	};
};