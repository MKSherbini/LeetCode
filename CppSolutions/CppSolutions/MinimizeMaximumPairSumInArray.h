#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class MinimizeMaximumPairSumInArray
{
public:
	// 171 ms, faster than 94.04% : 96.5 MB, less than 94.23%
	int solution(vector<int> nums) {
		sort(begin(nums), end(nums));
		int n = size(nums);
		int ans = 0;
		for (size_t i = 0; i * 2 < n; i++) {
			ans = max(ans, nums[i] + nums[n - i - 1]);
		}

		return ans;
	}
	vector<int> output = {
		7,
		8
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,5,2,3},
		{3,5,4,2,4,6}
	};
};