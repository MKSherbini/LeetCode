#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/permutations-ii/

class PermutationsII
{
public:
	// WA
	vector<vector<int>> solution(vector<int>& nums) {
		vector<vector<int>> ans;
		set<int> used;
		curse(nums, ans, 0, used);
		Printer::print(ans);
		return ans;
	}
	void curse(vector<int>& nums, vector<vector<int>>& ans, int index, set<int>& used) {
		if (index >= nums.size())
			return ans.push_back(nums);

		curse(nums, ans, index + 1, used);
		if (used.count(nums[index]) == 0) {
			for (int i = index + 1; i < nums.size(); i++)
			{
				if (nums[i] == nums[index]) continue;
				swap(nums[index], nums[i]);
				curse(nums, ans, index + 1, used);
				swap(nums[index], nums[i]);
			}
		}
	}
	vector<vector<vector<int>>> output = {
		{{1,1,2},{1,2,1},{2,1,1}},
		{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}},
		{{1,1,2,2},{1,2,1,2},{1,2,2,1},{1,2,2,1},{2,1,1,2},{2,1,2,1},{2,2,1,1}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,1,2},
		{1,2,3},
		{1,1,2,2}
	};
};