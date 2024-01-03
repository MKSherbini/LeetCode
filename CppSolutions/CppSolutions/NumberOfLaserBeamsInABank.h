#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03

class NumberOfLaserBeamsInABank
{
public:
	// 73 ms, faster than 97.42% : 23.1 MB, less than 99.59%
	int solution(vector<string> bank) {
		int last = 0, ans = 0;
		for (auto& v : bank) {
			int ones = count_if(begin(v), end(v), [](const auto& x) {return x == '1'; });
			ans += ones * last;
			if (ones)
				last = ones;
		}
		return ans;
	}
	vector<int> output = {
		8,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"011001","000000","010100","001000"},
		{"000","111","000"}
	};
};