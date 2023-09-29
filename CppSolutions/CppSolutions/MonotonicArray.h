#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/monotonic-array/

class MonotonicArray
{
public:
	// 107 ms, faster than 94.77% : 96.7 MB, less than 22.05%
	bool solution(vector<int> nums) {
		int n = size(nums);
		if (n <= 2) return 2;

		int i = 1;
		while (i < n&& nums[i] == nums[i - 1]) {
			++i;
		}
		if (i == n) return true;

		bool inc = nums[i] > nums[i - 1];

		for (; i < n; i++) {
			if ((inc && nums[i] >= nums[i - 1])
				|| (!inc && nums[i] <= nums[i - 1]))
				continue;
			else
				return false;
		}

		return true;
	}
	vector<int> output = {
		true,
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,2,3},
		{6,5,4,4},
		{1,3,2}
	};
};