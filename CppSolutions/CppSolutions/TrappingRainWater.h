#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/trapping-rain-water/

class TrappingRainWater
{
public:
	// 11 ms, faster than 98.33% : 19.6 MB, less than 99.89%
	int solution(vector<int> height) {
		int mxl = 0, mxr = 0, l = 0, r = size(height) - 1, ans = 0;
		while (l <= r) {
			mxl = max(mxl, height[l]);
			mxr = max(mxr, height[r]);
			if (mxl > mxr)
				ans += mxr - height[r--];
			else
				ans += mxl - height[l++];
		}
		return ans;
	}
	vector<int> output = {
		6,
		9
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{0,1,0,2,1,0,1,3,2,1,2,1},
		{4,2,0,3,2,5}
	};
};