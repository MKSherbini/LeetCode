#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/non-decreasing-array/

class NonDecreasingArray
{
public:
	// 30 ms, faster than 85.25% : 26.8 MB, less than 97.48%
	bool solution(vector<int> nums) {
		int changes = 0;
		for (size_t i = 1; i < size(nums); i++)
			if (nums[i] < nums[i - 1])
				if (!changes)
					if (i + 1 == size(nums))
						return 1;
					else if (nums[i + 1] >= nums[i - 1])
						nums[i] = nums[i - 1], changes++;
					else if (i == 1 || nums[i] >= nums[i - 2])
						nums[i - 1] = nums[i], changes++;
					else
						return 0;
				else
					return 0;
		Printer::print(nums);
		return changes <= 1;
	}
	vector<int> output = {
		true,
		false,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,4,2,3},
		{4,2,1},
		{3,4,2,3},
	};
};