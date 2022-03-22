#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/subsets/

class Subsets
{
public:
	// 0 ms, faster than 100% : 10.6 MB, less than 33.27%
	vector<vector<int>> solution(vector<int> nums) {
		vector<vector<int>> ans;
		curse(nums, ans, *new vector<int>{}, 0);
		return ans;
	}
	void curse(vector<int>& nums, vector<vector<int>>& ans, vector<int>& row, int st) {
		if (st == nums.size()) return ans.push_back(row);

		curse(nums, ans, row, st + 1);
		row.push_back(nums[st]);
		curse(nums, ans, row, st + 1);
		row.pop_back();
	}
	// 0 ms, faster than 100% : 6.9 MB, less than 99.18%
	vector<vector<int>> solution2(vector<int> nums) {
		vector<vector<int>> ans = { {} };
		int set = (1 << nums.size()) - 1;

		while (set)
		{
			vector<int> row;
			for (int i = 1, it = 0; i <= set; i <<= 1, it++)
				if (i & set) row.push_back(nums[it]);
			ans.push_back(row);
			set--;
		}
		Printer::printAll(ans.size());
		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}},
		{{},{0}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3},
		{0}
	};
};