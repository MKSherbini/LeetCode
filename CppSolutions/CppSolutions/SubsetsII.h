#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/subsets-ii/

class SubsetsII
{
public:
	// 0 ms, faster than 100% : 11.6 MB, less than 24.27%
	vector<vector<int>> solution(vector<int> nums) {
		vector<vector<int>> ans;
		sort(begin(nums), end(nums));
		map<int, int> duplicates;
		curse(nums, ans, *new vector<int>{}, 0);

		for (size_t i = 1; i < nums.size(); i++)
			if (nums[i - 1] == nums[i]) duplicates[nums[i]]++;

		Printer::print(duplicates);
		vector<vector<int>> ans2;

		for (auto v : ans) {
			vector<vector<int>> added(1, v);
			for (auto num : duplicates) {
				//Printer::printAll(num.first, "->", v);
				for (size_t i = 0, addedSize = added.size(); i < addedSize; i++)
				{
					vector<int> row(added[i]);
					if (find(begin(row), end(row), num.first) != end(row)) {
						for (size_t i = 0; i < num.second; i++)
						{
							row.push_back(num.first);
							//Printer::printAll("added ", v);
							added.push_back(row);
						}
					}
				}
			}
			ans2.insert(end(ans2), begin(added), end(added));
		}

		return ans2;
	}
	void curse(vector<int>& nums, vector<vector<int>>& ans, vector<int>& row, int i) {
		if (i == nums.size()) return ans.push_back(row);

		curse(nums, ans, row, i + 1);
		//bool inRow = find(begin(row), end(row), nums[i]) != end(row);
		//bool inNums = find(begin(nums), begin(nums) + i, nums[i]) != begin(nums) + i;
		//bool cond2 = inNums && !inRow;
		if (i > 0 && nums[i - 1] == nums[i])
			return;

		row.push_back(nums[i]);
		curse(nums, ans, row, i + 1);
		row.pop_back();

	}
	vector<vector<vector<int>>> output = {
		{{},{1},{1,2},{1,2,2},{2},{2,2}},
		{{},{0}},
		{{},{2},{2,2},{2,2,2}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,2},
		{0},
		{2,2,2}
	};
};