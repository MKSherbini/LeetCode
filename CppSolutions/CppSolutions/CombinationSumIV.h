#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/combination-sum-iv/

class CombinationSumIV
{
public:
	// 0 ms, faster than 100% : 6.5 MB, less than 91.95%
	int solution(vector<int> nums, int target) {
		vector mem(vector(target + 1, -1));
		return	f(nums, mem, target);
	}
	int f(vector<int>& nums, vector<int>& mem, int sum) {
		if (sum < 0) return 0;
		if (sum == 0) return 1;
		if (mem[sum] != -1) return mem[sum];

		int ret = 0;
		for (size_t i = 0; i < size(nums); i++)
			ret += f(nums, mem, sum - nums[i]);

		return mem[sum] = ret;
	}
	vector<int> output = {
		7,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3},
		{9}
	};
	vector<int> input2 = {
		4,
		3
	};
};