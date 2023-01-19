#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-sum-circular-subarray/

class MaximumSumCircularSubarray
{
public:
	// 44 ms, faster than 99.4% : 39.7 MB, less than 95.83%
	int solution(vector<int> nums) {
		int n = size(nums);

		int sum = 0, mx = nums[0], mxHere = 0, mn = nums[0], mnHere = 0;
		for (auto x : nums) {
			mxHere = max(mxHere, 0) + x;
			mx = max(mx, mxHere);
			mnHere = min(mnHere, 0) + x;
			mn = min(mn, mnHere);
			sum += x;
		}

		return sum == mn ? mx : max(mx, sum - mn);
	}
	vector<int> output = {
		3,
		10,
		-2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,-2,3,-2},
		{5,-3,5},
		{-3,-2,-3}
	};
};