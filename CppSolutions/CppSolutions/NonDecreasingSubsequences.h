#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/non-decreasing-subsequences/

class NonDecreasingSubsequences
{
public:
	// 22 ms, faster than 100% : 30.6 MB, less than 34.81%
	vector<vector<int>> solution(vector<int> nums) {
		vector<vector<int>> ans;
		vector<int> row;
		f(nums, ans, row, 0);
		return ans;
	}
	void f(vector<int>& nums, vector<vector<int>>& ans, vector<int>& row, int i) {
		if (i == size(nums)) {
			if (row.size() > 1) ans.push_back(row);
			return;
		}

		if (row.empty() || row.back() != nums[i])
			f(nums, ans, row, i + 1);

		if (row.empty() || row.back() <= nums[i]) {
			row.push_back(nums[i]);
			f(nums, ans, row, i + 1);
			row.pop_back();
		}
	}

	// 94 ms, faster than 55.01% : 20.3 MB, less than 90.64%
	vector<vector<int>> solution2(vector<int> nums) {
		vector<vector<int>> ans;
		vector<int> row;
		f(nums, ans, row, 0, -1);
		sort(begin(ans), end(ans));
		ans.erase(unique(begin(ans), end(ans)), end(ans));
		return ans;
	}
	void f(vector<int>& nums, vector<vector<int>>& ans, vector<int>& row, int taken, int i) {
		for (size_t j = i + 1; j < size(nums); j++) {
			int vis = (taken & (1 << j));
			if (!vis && (i == -1 || nums[i] <= nums[j])) {
				row.push_back(nums[j]);
				f(nums, ans, row, taken | (1 << j), j);
				row.pop_back();
			}
		}
		if (row.size() > 1) ans.push_back(row);
	}
	vector<vector<vector<int>>> output = {
		{{4,6},{4,6,7},{4,6,7,7},{4,7},{4,7,7},{6,7},{6,7,7},{7,7}},
		{{4,4}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{4,6,7,7},
		{4,4,3,2,1}
	};
};