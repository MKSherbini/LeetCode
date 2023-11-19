#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/?envType=daily-question&envId=2023-11-19

class ReductionOperationsToMakeTheArrayElementsEqual
{
public:
	// 140 ms, faster than 94.79% : 82.9 MB, less than 98.16%
	int solution(vector<int> nums) {
		int n = size(nums);
		sort(begin(nums), end(nums), greater());

		int ans = 0;
		for (size_t i = 1; i < n; i++) {
			if (nums[i] != nums[i - 1]) ans += i;
		}

		return ans;
	}
	vector<int> output = {
		3,
		0,
		4
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{5,1,3},
		{1,1,1},
		{1,1,2,2,3}
	};
};