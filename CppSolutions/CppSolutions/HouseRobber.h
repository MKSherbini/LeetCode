#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/house-robber/

class HouseRobber
{
public:
	// 0 ms, faster than 100.00% : 7.5 MB, less than 99.86%
	int solution(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		nums[1] = max(nums[1], nums[0]);
		for (int i = 2; i < nums.size(); i++)
			nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
		return nums[nums.size() - 1];
	}

	// 0 ms, faster than 100.00% : 7.6 MB, less than 72.16%
	int solution3(vector<int>& nums) {
		vector<int> mem(nums.size(), -1);
		return curse3(nums, mem, 0);
	}
	int curse3(vector<int>& nums, vector<int>& mem, int i) {
		if (i >= nums.size()) return 0;

		if (mem[i] != -1) return mem[i];

		return mem[i] = max(
			nums[i] + curse3(nums, mem, i + 2),
			curse3(nums, mem, i + 1)
		);
	}

	// 0 ms, faster than 100.00% : 10.3 MB, less than 5.33%
	int solution2(vector<int>& nums) {
		vector<pair<int, vector<int>>> mem(nums.size(), { -1,{} });

		auto ret = curse2(nums, mem, 0);
		//Printer::print(ret.second);
		return ret.first;
	}
	pair<int, vector<int>> curse2(vector<int>& nums, vector<pair<int, vector<int>>>& mem, int i) {
		if (i >= nums.size()) return { 0 , {} };

		if (mem[i].first != -1) return mem[i];

		auto step2 = curse2(nums, mem, i + 2);
		auto step1 = curse2(nums, mem, i + 1);
		int pick = nums[i] + step2.first;
		int leave = step1.first;

		int ret = max(pick, leave);
		if (pick == ret) {
			step2.second.push_back(i);
			return mem[i] = { ret , step2.second };
		}
		return mem[i] = { ret ,step1.second };
	}
	vector<int> output = {
		4,
		12,
		16,
		311,
	};
	vector<vector<int>> input1 = {
		{1,2,3,1},
		{2,7,9,3,1},
		{7,2,3,9,1},
		{7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7,2,3,9,1,7},
	};
};

