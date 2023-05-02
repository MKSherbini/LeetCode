#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sign-of-the-product-of-an-array/

class SignOfTheProductOfAnArray
{
public:
	// 0 ms, faster than 100% : 10.1 MB, less than 99.27%
	int solution(vector<int> nums) {
		int ans = 1;
		for (auto x : nums) {
			if (x < 0) ans *= -1;
			else if (x == 0) return 0;
		}
		if (ans > 0) return 1;
		return -1;
	}
	vector<int> output = {
		1,
		0,
		-1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{-1,-2,-3,-4,3,2,1},
		{1,5,0,2,-3},
		{-1,1,-1,1,-1}
	};
};