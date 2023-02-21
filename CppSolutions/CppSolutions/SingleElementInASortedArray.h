#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/single-element-in-a-sorted-array/

class SingleElementInASortedArray
{
public:
	// 24 ms, faster than 86.99% : 22.2 MB, less than 93.44%
	int solution(vector<int> nums) {
		int st = 0, end = size(nums) - 1;
		if (end == st) return nums[0];

		while (st <= end) {
			int md = st + (end - st) / 2;
			Printer::print(st, end, md, nums[md]);
			if (nums[st] != nums[st + 1])
				return nums[st];
			if (nums[end] != nums[end - 1])
				return nums[end];

			if (md % 2 == 0)
				if (nums[md] == nums[md + 1])
					st = md + 2;
				else
					end = md;

			if (md % 2 == 1)
				if (nums[md] == nums[md - 1])
					st = md + 1;
				else
					end = md - 1;
		}
		return -1;
	}
	vector<int> output = {
		2,
		10
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,1,2,3,3,4,4,8,8},
		{3,3,7,7,10,11,11}
	};
};