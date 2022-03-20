#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/subsets/

class Subsets
{
public:
	// 0 ms, faster than 100% : 6.9 MB, less than 99.18%
	vector<vector<int>> solution(vector<int> nums) {
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