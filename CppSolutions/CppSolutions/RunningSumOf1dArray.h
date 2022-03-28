#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/running-sum-of-1d-array/

class RunningSumOf1dArray
{
public:
	// 0 ms, faster than 100% : 8.3 MB, less than 99.77%
	vector<int> solution(vector<int> nums) {
		for (size_t i = 1; i < nums.size(); i++)
			nums[i] += nums[i - 1];
		return nums;
	}
	vector<vector<int>> output = {
		{1,3,6,10},
		{1,2,3,4,5},
		{3,4,6,16,17}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{1,1,1,1,1},
		{3,1,2,10,1}
	};
};