#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/jump-game-ii/

class JumpGameII
{
public:
	// 512 ms, faster than 21.76% : 17.8 MB, less than 10.19%
	int solution(vector<int> nums) {
		vector<int> mem(nums.size(), -1);
		return curse(nums, mem, 0);
	}
	int curse(vector<int>& nums, vector<int>& mem, int i) {
		if (i >= nums.size()) return OO;
		if (i + 1 == nums.size()) return 0;
		if (mem[i] != -1) return mem[i];

		int ret = OO;

		for (size_t j = 1; j <= nums[i]; j++)
			ret = min(ret, 1 + curse(nums, mem, i + j));

		return mem[i] = ret;
	}
	const int OO = (int)1e8;
	vector<int> output = {
		2,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,3,1,1,4},
		{2,3,0,1,4}
	};
};