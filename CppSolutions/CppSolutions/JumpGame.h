#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/jump-game/

class JumpGame
{
public:
	// 53 ms, faster than 99.31% : 48.2 MB, less than 94.13%
	bool solution(vector<int> nums) {
		int n = size(nums);
		int out = n - 1;

		for (int i = n - 2; i >= 0; i--)
			if (out <= i + nums[i]) out = i;

		return out == 0;
	}

	// 144 ms, faster than 63.27% : 66.3 MB, less than 6.72%
	bool solution3(vector<int> nums) {
		int n = size(nums);
		set<int> s;

		s.insert(n - 1);
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] + i + 1 >= n) s.insert(i);
			else {
				auto it = s.upper_bound(i);
				if (it != end(s) && *it <= i + nums[i]) s.insert(i);
			}
		}

		return s.count(0);
	}

	// 1277 ms, faster than 5.1% : 51 MB, less than 7.05%
	bool solution2(vector<int> nums) {
		vector<int> mem(nums.size(), -1);
		return curse(nums, mem, 0);
	}
	bool curse(vector<int>& nums, vector<int>& mem, int i) {
		if (i + 1 >= nums.size()) return 1;
		if (mem[i] != -1) return mem[i];

		bool ret = 0;

		for (size_t j = 1; j <= nums[i]; j++)
		{
			ret |= curse(nums, mem, i + j);
			if (ret) break;
		}

		return mem[i] = ret;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,3,1,1,4},
		{3,2,1,0,4}
	};
};