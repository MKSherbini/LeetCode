#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-subarray/

class MaximumSubarray
{
public:
	// 104 ms, faster than 95.36% : 67.6 MB, less than 91.16%
	int solution(vector<int> nums) {
		int mx = -9999999, sum = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			sum += nums[i];
			mx = max(mx, sum);
			sum = max(sum, 0);
		}
		return mx;
	}

	/*int curse(vector<int>& nums, vector<vector<int>>& mem, int i, int j) {
		if (i >= nums.size() || j >= nums.size()) return 0;
		if (mem[i][j] != -OO) return mem[i][j];
		int ret = -OO;
		if (i < j)
			ret = max(ret, -nums[i] + curse(nums, mem, i + 1, j));
		ret = max(ret, nums[j] + curse(nums, mem, i, j + 1));

		return mem[i][j] = (ret == OO ? 0 : ret);
	}*/
	const int OO = (int)55;
	vector<int> output = {
		6,
		1,
		23
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{-2,1,-3,4,-1,2,1,-5,4},
		{1},
		{5,4,-1,7,8}
	};
};