#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/findFirstAndLastPositionOfElementInSortedArray/

class FindFirstAndLastPositionOfElementInSortedArray
{
public:
	// 4 ms, faster than 96.36% : 13.4 MB, less than 99.99%
	vector<int> solution(vector<int>& nums, int target) {
		int idx = lower_bound(begin(nums), end(nums), target) - begin(nums);
		if (idx == nums.size() || nums[idx] != target) return { -1,-1 };

		return { idx, int(upper_bound(begin(nums) + idx, end(nums), target) - begin(nums)) - 1 };
	}
	vector<vector<int>> output = {
		{3,4},
		{0,0},
		{-1,-1},
		{-1,-1},
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{5,7,7,8,8,10},
		{5,7,7,8,8,10},
		{5,7,7,8,8,10},
		{},
	};
	vector<int> input2 = {
		8,
		5,
		11,
		0,
	};
};

