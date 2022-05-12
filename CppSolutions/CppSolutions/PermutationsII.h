#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/permutations-ii/

class PermutationsII
{
public:
	// 0 ms, faster than 100% : 6.6 MB, less than 35.07%
	vector<vector<int>> solution(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(begin(nums), end(nums));
		curse(nums, ans, {}, 0);
		return ans;
	}
	void curse(vector<int>& nums, vector<vector<int>>& ans, vector<int> row, int taken) {
		if (row.size() == nums.size()) return ans.push_back(row);

		for (int i = 0; i < nums.size(); i++)
		{
			int vis = (taken & (1 << i));
			int visLast = (taken & (1 << (i - 1)));
			if (vis || i > 0 && visLast && nums[i] == nums[i - 1]) continue;
			row.push_back(nums[i]);
			curse(nums, ans, row, taken | (1 << i));
			row.pop_back();
		}
	}

	// WA
	vector<vector<int>> solution2(vector<int>& nums) {
		vector<vector<int>> ans;
		set<int> used;
		curse2(nums, ans, 0, used);
		Printer::print(ans);
		return ans;
	}
	void curse2(vector<int>& nums, vector<vector<int>>& ans, int index, set<int>& used) {
		if (index >= nums.size())
			return ans.push_back(nums);

		curse2(nums, ans, index + 1, used);
		if (used.count(nums[index]) == 0) {
			for (int i = index + 1; i < nums.size(); i++)
			{
				if (nums[i] == nums[index]) continue;
				swap(nums[index], nums[i]);
				curse2(nums, ans, index + 1, used);
				swap(nums[index], nums[i]);
			}
		}
	}
	vector<vector<vector<int>>> output = {
		{{1,1,2},{1,2,1},{2,1,1}},
		{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}},
		{{1,1,2,2},{1,2,1,2},{1,2,2,1},{2,1,1,2},{2,1,2,1},{2,2,1,1}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,1,2},
		{1,2,3},
		{1,1,2,2}
	};
};