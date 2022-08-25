#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/power-of-three/

class PowerOfThree
{
public:
	// fastest
	bool solution3(int n) {
		return n > 0 && 1162261467 % n == 0;
	}
	// faster
	bool solution(int n) {
		double epsilon = 1e-10;
		double ans = log(n) / log(3);
		return abs(floor(ans + epsilon) - ans) <= epsilon;
	}
	// 11 ms, faster than 98.89% : 5.7 MB, less than 98.87%
	bool solution2(int n) {
		if (n == 0) return 0;
		while (n % 3 == 0)
			n /= 3;
		return n == 1;
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		27,
		0,
		9
	};
};