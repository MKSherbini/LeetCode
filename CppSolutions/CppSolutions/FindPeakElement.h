#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-peak-element/

class FindPeakElement
{
public:
	// 0 ms, faster than 100% : 8.7 MB, less than 99.51%
	int solution(vector<int> nums) {
		int lo = 0, hi = nums.size() - 1;
		if (hi > 0)
			if (nums[0] > nums[1])
				return 0;
			else if (nums[hi] > nums[hi - 1])
				return hi;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			Printer::print(nums[lo]);
			Printer::print(nums[mid]);
			Printer::print(nums[hi], 1);
			if (mid + 1 == nums.size()) hi = mid;
			else if (mid - 1 < 0) lo = mid;
			else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
				return mid;
			else if (nums[mid + 1] > nums[mid - 1])
				lo = mid;
			else hi = mid;
		}
		return lo;
	}
	vector<int> output = {
		2,
		5,
		0,
		0,
		2,
		1,
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,1},
		{1,2,1,3,5,6,4},
		{4},
		{4,3},
		{2,3,4},
		{1,7,6,5,4,3,2,1},
	};
};
//ricardo 
//mahmoud mobarak
//jumia pay service
