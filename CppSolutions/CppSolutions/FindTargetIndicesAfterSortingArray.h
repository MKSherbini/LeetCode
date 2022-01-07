#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-target-indices-after-sorting-array/

class FindTargetIndicesAfterSortingArray
{
public:
	// 4 ms, faster than 85.55% : 11.6 MB, less than 82.40%
	vector<int> solution2(vector<int>& nums, int target) {
		sort(begin(nums), end(nums));
		int it = lower_bound(begin(nums), end(nums), target) - begin(nums);

		vector<int> ans;
		while (it < nums.size() && nums[it] == target)
			ans.push_back(it++);

		return ans;
	}

	// 0 ms, faster than 100.00% : 11.6 MB, less than 82.40%
	vector<int> solution(vector<int>& nums, int target) {
		int less = 0, equal = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] < target) less++;
			else if (nums[i] == target) equal++;

		vector<int> ans(equal);
		for (int i = less; i < less + equal; i++)
			ans[i - less] = i;

		return ans;
	}

	vector<vector<int>>  output = {
		{1,2},
		{3},
		{},
		{},
	};
	vector<vector<int>>  input1 = {
		{1,2,5,2,3},
		{1,2,5,2,3},
		{1,2,5,2,3},
		{1,2,5,2,3},
	};
	vector<int>  input2 = {
		2,
		3,
		6,
		0,
	};
};

