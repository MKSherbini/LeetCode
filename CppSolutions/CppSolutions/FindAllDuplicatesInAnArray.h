#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-all-duplicates-in-an-array/

class FindAllDuplicatesInAnArray
{
public:
	// 19 ms, faster than 99.79% : 37 MB, less than 62.06%
	vector<int> solution(vector<int> nums) {
		int n = size(nums);
		vector<int> f(n);
		for (auto x : nums) {
			f[x - 1]++;
		}

		vector<int> ans;
		for (size_t i = 0; i < n; i++) {
			if (f[i] == 2) ans.push_back(i + 1);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{2,3},
		{1},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{4,3,2,7,8,2,3,1},
		{1,1,2},
		{1}
	};
};