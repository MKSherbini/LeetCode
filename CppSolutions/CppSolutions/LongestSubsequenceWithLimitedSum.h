#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-subsequence-with-limited-sum/

class LongestSubsequenceWithLimitedSum
{
public:
	// 7 ms, faster than 100% : 13.4 MB, less than 98.2%
	vector<int> solution(vector<int> nums, vector<int> queries) {
		sort(begin(nums), end(nums), greater());

		nums.back() *= -1;
		for (int i = size(nums) - 2; i >= 0; i--)
			nums[i] = -nums[i] + nums[i + 1];

		for (auto& x : queries)
			x = end(nums) - lower_bound(begin(nums), end(nums), -x);

		return queries;
	}
	vector<vector<int>> output = {
		{2,3,4},
		{0}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{4,5,2,1},
		{2,3,4,5}
	};
	vector<vector<int>> input2 = {
		{3,10,21},
		{1}
	};
};