#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

class DivideArrayIntoArraysWithMaxDifference
{
public:
	// 110 ms, faster than 99.91% : 119.4 MB, less than 39.78%
	vector<vector<int>> solution(vector<int> nums, int k) {
		int n = size(nums);
		if (n < 3 || n % 3) return {};
		sort(begin(nums), end(nums));
		vector<vector<int>> ans;
		for (size_t i = 0; i < n; i += 3) {
			if (nums[i + 2] - nums[i] <= k) {
				ans.push_back({ nums[i], nums[i + 1], nums[i + 2] });
			}
			else {
				return {};
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1,1,3},{3,4,5},{7,8,9}},
		{}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,4,8,7,9,3,5,1},
		{1,3,3,2,7,3}
	};
	vector<int> input2 = {
		2,
		3
	};
};