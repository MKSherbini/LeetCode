#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/wiggle-subsequence/

class WiggleSubsequence
{
public:
	// 303 ms, faster than 5.09% : 96.1 MB, less than 5.01%
	int solution(vector<int> nums) {
		if (size(nums) == 1) return 1;
		vector<vector<vector<int>>> mem(size(nums), vector<vector<int>>(size(nums), vector<int>(3, -1)));
		int ans = 1 + curse(nums, mem, 1, 0, -1);
		//Printer::print(mem);
		return ans;
	}
	int curse(vector<int>& nums, vector<vector<vector<int>>>& mem, int i, int lastI, int dif) {
		//Printer::print(i, lastI, dif);
		if (i >= size(nums)) return 0;
		if (mem[i][lastI][dif + 1] != -1)
			return mem[i][lastI][dif + 1];

		if ((nums[i] != nums[lastI]) && ((nums[i] > nums[lastI]) != dif))
			return 1 + curse(nums, mem, i + 1, i, (nums[i] > nums[lastI]));

		if ((nums[i] == nums[lastI]))
			return curse(nums, mem, i + 1, lastI, dif);


		int mx = curse(nums, mem, i + 1, lastI, dif);
		mx = max(mx, curse(nums, mem, i + 1, i, dif));

		return mem[i][lastI][dif + 1] = mx;
	}
	vector<int> output = {
		6,
		7,
		2,
		1,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,7,4,9,2,5},
		{1,17,5,10,13,15,10,5,16,8},
		{1,2,3,4,5,6,7,8,9},
		{0,0,0},
		{3,3,3,2,5}
	};
};
