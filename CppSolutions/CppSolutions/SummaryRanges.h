#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/summary-ranges/

class SummaryRanges
{
public:
	// 0 ms, faster than 100% : 6.8 MB, less than 96.03%
	vector<string> solution(vector<int> nums) {
		int n = size(nums);
		vector<string> ans;
		for (size_t i = 0; i < n; i++) {
			size_t j = i + 1;
			for (; j < n; j++) {
				if (nums[i] + j - i != nums[j]) break;
			}
			j--;
			if (i == j)
				ans.push_back(to_string(nums[i]));
			else
				ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));

			i = j;
		}
		return ans;
	}
	vector<vector<string>> output = {
		{"0->2","4->5","7"},
		{"0","2->4","6","8->9"}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{0,1,2,4,5,7},
		{0,2,3,4,6,8,9}
	};
};