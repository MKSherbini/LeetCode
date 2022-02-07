#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/rotate-array/

class RotateArray
{
public:
	//24 ms, faster than 94.88% : 24.8 MB, less than 99.47%
	vector<int> solution(vector<int> nums, int k) {
		int sz = nums.size();
		int steps = 0;
		int next = 0;
		int prev = nums[0];
		int cycleStart = 0;
		while (steps++ < sz)
		{
			next = (next + k) % sz;
			int temp = nums[next];
			nums[next] = prev;
			prev = temp;
			if (next <= cycleStart && next < sz - 1) {
				++cycleStart;
				next = cycleStart;
				prev = nums[next];
			}
		}
		return nums;
	}
	//28 ms, faster than 86.13% : 25.6 MB, less than 30.05%
	vector<int> solution2(vector<int> nums, int k) {
		int sz = nums.size();
		vector<int> temp(nums);
		for (int i = 0; i < sz; i++)
		{
			int oi = (i + k) % sz;
			nums[oi] = temp[i];
		}
		return nums;
	}
	vector<vector<int>> output = {
		{5,6,7,1,2,3,4},
		{3,99,-1,-100}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4,5,6,7},
		{-1,-100,3,99}
	};
	vector<int> input2 = {
		3,
		2
	};
};