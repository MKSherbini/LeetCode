#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/single-number/

class SingleNumber
{
public:
	// 8 ms, faster than 99.85% : 16.8 MB, less than 99.14%
	int solution(vector<int>& nums) {
		int ret = nums[0];
		for (int i = 1; i < nums.size(); i++)
			ret ^= nums[i];
		return ret;
	}
	vector<int> output = {
		1,
		4,
		1,
	};
	vector<vector<int>> input1 = {
		{2,2,1},
		{4,1,2,1,2},
		{1},
	};
};

