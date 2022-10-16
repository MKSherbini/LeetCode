#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimize-maximum-of-array/

class MinimizeMaximumOfArray
{
public:
	// 119 ms, faster than 100% : 71.2 MB, less than 12.5%
	int solution(vector<int> nums) {
		long sum = 0, res = 0;

		for (int i = 0; i < size(nums); ++i) {
			sum += nums[i];
			res = max(res, (sum + i) / (i + 1));
		}
		
		return res;
	}
	vector<int> output = {
		5,
		10,
		16
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,7,1,6},
		{10,1},
		{13,13,20,0,8,9,9}
	};
};