#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2023-12-06

class CalculateMoneyInLeetcodeBank
{
public:
	// 0 ms, faster than 100% : 6.2 MB, less than 71.05%
	int solution(int n) {
		int d = n / 7, mod = n % 7;
		int ans = 28 * d + d * (d - 1) / 2 * 7;
		ans += mod * (mod + 1) / 2 + mod * d;
		return ans;
	}
	vector<int> output = {
		10,
		37,
		96
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		4,
		10,
		20
	};
};