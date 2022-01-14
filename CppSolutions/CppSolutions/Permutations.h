#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/permutations/

class Permutations
{
public:
	// 0 ms, faster than 100.00% : 7.4 MB, less than 98.84%
	vector<vector<int>> solution(vector<int>& nums) {
		vector<vector<int>> ans;
		curse(nums, ans, 0);
		return ans;
	}
	void curse(vector<int>& nums, vector<vector<int>>& ans, int index) {
		if (index >= nums.size()) return ans.push_back(nums);

		for (int i = index+1; i < nums.size(); i++)
		{
			swap(nums[index], nums[i]);
			curse(nums, ans, index + 1);
			swap(nums[index], nums[i]);
		}
	}

	// 3 ms, faster than 76.65% : 8.2 MB, less than 19.38%
	vector<vector<int>> solution3(vector<int>& nums) {
		vector<vector<int>> ans;
		curse3(nums, ans, {}, 0);
		return ans;
	}
	void curse3(vector<int>& nums, vector<vector<int>>& ans, vector<int> row, int taken) {
		if (row.size() == nums.size()) return ans.push_back(row);

		for (int i = 0; i < nums.size(); i++)
		{
			int vis = (taken & (1 << i));
			if (!vis) {
				row.push_back(nums[i]);
				curse3(nums, ans, row, taken | (1 << i));
				row.pop_back();
			}
		}
	}

	// 4 ms, faster than 70.81% : 8.3 MB, less than 19.38%
	vector<vector<int>> solution2(vector<int>& nums) {
		vector<vector<int>> ans;
		curse2(nums, ans, {});
		return ans;
	}
	void curse2(vector<int>& nums, vector<vector<int>>& ans, vector<int> row) {
		if (row.size() == nums.size()) return ans.push_back(row);

		for (int i = 0; i < nums.size(); i++)
		{
			if (find(begin(row), end(row), nums[i]) == end(row)) {
				row.push_back(nums[i]);
				curse2(nums, ans, row);
				row.pop_back();
			}
		}
	}
	vector<vector<vector<int>>> output = {
		{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}},
		{{0,1},{1,0}},
		{{1}},
	};
	vector<vector<int>> input1 = {
		{1,2,3},
		{0,1},
		{1},
	};
};

