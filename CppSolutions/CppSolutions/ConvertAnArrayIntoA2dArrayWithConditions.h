#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

class ConvertAnArrayIntoA2dArrayWithConditions
{
public:
	// 8 ms, faster than 79.34% : 30.8 MB, less than 11.66%
	vector<vector<int>> solution(vector<int> nums) {
		vector f(200, 0);
		for (auto x : nums) {
			f[x - 1]++;
		}

		vector<vector<int>> ans;
		for (size_t i = 0; i < 200; i++) {
			if (!f[i]) continue;

			for (size_t j = 0; j < f[i]; j++) {
				if (size(ans) == j) ans.push_back({});
				ans[j].push_back(i + 1);
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1,3,4,2},{1,3},{1}},
		{{4,3,2,1}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,3,4,1,2,3,1},
		{1,2,3,4}
	};
};