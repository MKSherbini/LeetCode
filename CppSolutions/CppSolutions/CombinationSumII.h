#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/combination-sum-ii/

class CombinationSumII
{
public:
	// 159 ms, faster than 5.03% : 41 MB, less than 5.68%
	vector<vector<int>> solution(vector<int> candidates, int target) {
		vector<vector<int>> ans;
		map<int, int> cands;
		for (size_t i = 0; i < candidates.size(); i++)
			cands[candidates[i]]++;

		curse(cands, ans, target, cands.begin(), 0, {});
		return ans;
	}
	void curse(map<int, int>& nums, vector<vector<int>>& ans, int sum, map<int, int>::iterator it, int cnt, vector<int> row) {
		if (sum == 0) return ans.push_back(row);
		if (it == nums.end() || sum < 0) return;

		it++;
		curse(nums, ans, sum, it, 0, row);
		it--;
		if (it->second <= cnt) return;
		row.push_back(it->first);
		curse(nums, ans, sum - it->first, it, cnt + 1, row);
	}

	vector<vector<vector<int>>> output = {
		{{1,1,6},{1,2,5},{1,7},{2,6}},
		{{1,2,2},{5}},
		{},
		{{1,1,6},{1,2,5},{1,7},{2,6}}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{10,1,2,7,6,1,5},
		{2,5,2,1,2},
		{1},
		{10,1,2,7,6,1,5}
	};
	vector<int> input2 = {
		8,
		5,
		2,
		8
	};
};