#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class SumOfEvenNumbersAfterQueries
{
public:
	// 110 ms, faster than 95.11% : 45.1 MB, less than 100%
	vector<int> solution(vector<int> nums, vector<vector<int>> queries) {
		int sum = 0;
		vector<int> ans(size(queries));
		for (auto x : nums)
			if (x % 2 == 0)
				sum += x;

		for (size_t i = 0; i < size(queries); i++)
		{
			int& x = nums[queries[i][1]];
			if (x % 2 == 0) sum -= x;
			x += queries[i][0];

			if (x % 2 == 0) sum += x;
			ans[i] = sum;
		}
		return ans;
	}
	vector<vector<int>> output = {
		{8,6,2,4},
		{0}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{1}
	};
	vector<vector<vector<int>>> input2 = {
		{{1,0},{-3,1},{-4,0},{2,3}},
		{{4,0}}
	};
};