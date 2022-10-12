#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/largest-perimeter-numsangle/

class LargestPerimeterTriangle
{
public:
	// 39 ms, faster than 94.03% : 21.7 MB, less than 96.06%
	int solution(vector<int> nums) {
		sort(begin(nums), end(nums), greater());

		for (int i = 2; i < size(nums); i++)
		{
			if (nums[i] + nums[i - 1] > nums[i - 2] &&
				nums[i - 1] + nums[i - 2] > nums[i]
				&& nums[i] + nums[i - 2] > nums[i - 1])
				return nums[i] + nums[i - 1] + nums[i - 2];
		}

		return 0;
	}
	vector<int> output = {
		5,
		0,
		10
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,1,2},
		{1,2,1},
		{3,2,3,4}
	};
};