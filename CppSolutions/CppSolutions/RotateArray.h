#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/rotate-array/

class RotateArray
{
public:
	vector<int> solution(vector<int>& nums, int k) {
		int sz = nums.size();
		vector<int> temp(nums);
		for (int i = 0; i < sz; i++)
		{
			int oi = (i + k) % sz;
			nums[oi] = temp[i];
		}
		return nums;
	}
};
