#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/house-robber-ii/

class HouseRobberIi
{
public:
	// 0 ms, faster than 100% : 7.8 MB, less than 60.08%
	int solution(vector<int> nums) {
		if (nums.size() == 1) return nums[0];
		vector<int> mem(nums.size(), -1);
		vector<int> v1(begin(nums) + 1, end(nums));
		nums.pop_back();
		int first = curse(v1, mem, 0);
		mem.assign(nums.size(), -1);
		return max(first, curse(nums, mem, 0));
	}
	int curse(vector<int>& nums, vector<int>& mem, int i) {
		if (i >= nums.size()) return 0;
		if (mem[i] != -1) return mem[i];

		return mem[i] = max(
			curse(nums, mem, i + 2) + nums[i],
			curse(nums, mem, i + 1)
		);
	}

	// ACC here but WA on LeetCode ???
	int solution2(vector<int> nums) {
		vector<int> mem(nums.size(), -1);
		int ret = curse2(nums, mem, 0, 0);
		Printer::print(mem);
		return ret;
	}
	int curse2(vector<int>& nums, vector<int>& mem, int i, bool pickedFirst) {
		if (i >= nums.size() || i == nums.size() - 1 && pickedFirst) return 0;
		if (mem[i] != -1) return mem[i];

		return mem[i] = max(
			curse2(nums, mem, i + 2, i == 0 ? 1 : pickedFirst) + nums[i],
			curse2(nums, mem, i + 1, pickedFirst)
		);
	}
	vector<int> output = {
		3,
		4,
		3,
		103
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,3,2},
		{1,2,3,1},
		{1,2,3},
		{1,3,1,3,100}
	};
};