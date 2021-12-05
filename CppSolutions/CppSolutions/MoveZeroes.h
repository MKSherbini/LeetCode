#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/move-zeroes/

class MoveZeroes
{
public:
	auto solution(vector<int>& nums) {
		int sz = nums.size();
		int it = 0;
		for (int i = 0; i < sz; i++)
		{
			if (nums[i] != 0) swap(nums[i], nums[it++]);
		}
		return nums;
	}
};

