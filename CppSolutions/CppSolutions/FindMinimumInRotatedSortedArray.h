#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class FindMinimumInRotatedSortedArray
{
public:
	// 0 ms, faster than 100% : 10 MB, less than 95.89%
	int solution(vector<int> nums) {
		if (nums.size() == 1) return nums[0];
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > nums[lo]) lo = mid;
			else hi = mid;
		}

		return min(nums[0], nums[lo + 1]);
	}
	vector<int> output = {
		1,
		0,
		0,
		9,
		0,
		0,
		0,
		0,
		0,
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,4,5,1,2},
		{4,5,6,7,0,1,2},
		{4,5,0,1,2},
		{9,10,11,13,15,17},
		{1,2,3,4,5,6,7,8,9,0},
		{3,4,5,6,7,8,9,10,0,1,2},
		{3,4,5,6,7,8,9,10,0},
		{0},
		{1,0},
	};
};