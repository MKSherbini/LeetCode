#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class ShortestUnsortedContinuousSubarray
{
public:
	// 34 ms, faster than 84.78% : 27.3 MB, less than 48.68%
	int solution(vector<int> nums) {
		vector<int> sorted(nums);
		sort(begin(sorted), end(sorted));

		int st = 0, end = nums.size() - 1;

		while (st <= end && sorted[st] == nums[st])
			st++;
		while (st <= end && sorted[end] == nums[end])
			end--;
		return end - st + 1;
	}
	vector<int> output = {
		5,
		0,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,6,4,8,10,9,15},
		{1,2,3,4},
		{1}
	};
};