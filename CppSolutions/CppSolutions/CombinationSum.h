#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/combination-sum/

class CombinationSum
{
public:
	// 3 ms, faster than 97.66% : 17.1 MB, less than 39.14%
	vector<vector<int>> solution(vector<int> candidates, int target) {
		vector<vector<int>> ans;
		vector<int> r;
		curse(candidates, ans, target, 0, r);
		return ans;
	}
	void curse(vector<int>& nums, vector<vector<int>>& ans, int sum, int i, vector<int>& row) {
		if (sum == 0) return ans.push_back(row);
		if (i == nums.size() || sum < 0) return;


		curse(nums, ans, sum, i + 1, row);
		row.push_back(nums[i]);
		curse(nums, ans, sum - nums[i], i, row);
		row.pop_back();
	}

	// 226 ms, faster than 13.03% : 79.3 MB, less than 10.97%
	vector<vector<int>> solution2(vector<int> candidates, int target) {
		vector<vector<int>> ans;
		curse2(candidates, ans, target, 0, {});
		return ans;
	}
	void curse2(vector<int>& nums, vector<vector<int>>& ans, int sum, int i, vector<int> row) {
		if (sum == 0) return ans.push_back(row);
		if (i == nums.size() || sum < 0) return;


		curse2(nums, ans, sum, i + 1, row);
		row.push_back(nums[i]);
		curse2(nums, ans, sum - nums[i], i, row);
	}

	vector<vector<vector<int>>> output = {
		{{2,2,3},{7}},
		{{2,2,2,2,2,2},{2,2,2,3,3},{2,2,2,6},{2,3,7},{3,3,3,3},{3,3,6},{6,6}},
		{{2,2,2,2},{2,3,3},{3,5}},
		{}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,3,6,7},
		{2,3,6,7},
		{2,3,5},
		{2}
	};
	vector<int> input2 = {
		7,
		12,
		8,
		1
	};
};