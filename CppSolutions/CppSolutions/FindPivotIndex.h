#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-pivot-index/?envType=study-plan-v2&envId=leetcode-75

class FindPivotIndex
{
public:
	// 11 ms, faster than 97.94% : 31 MB, less than 81.44%
	int solution(vector<int> nums) {
		int n = size(nums);
		int l = 0, r = accumulate(begin(nums), end(nums), 0);

		for (size_t i = 0; i < n; i++) {
			r -= nums[i];
			if (l == r) return i;
			l += nums[i];
		}

		return -1;
	}
	vector<int> output = {
		3,
		-1,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,7,3,6,5,6},
		{1,2,3},
		{2,1,-1}
	};
};