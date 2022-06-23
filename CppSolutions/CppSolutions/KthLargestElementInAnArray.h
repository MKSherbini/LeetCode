#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/kth-largest-element-in-an-array/

class KthLargestElementInAnArray
{
public:
	// 3 ms, faster than 99.32% : 9.9 MB, less than 97.44%
	int solution(vector<int> nums, int k) {
		sort(begin(nums), end(nums), greater());
		return nums[k - 1];
	}
	vector<int> output = {
		5,
		4
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{3,2,1,5,6,4},
		{3,2,3,1,2,4,5,5,6}
	};
	vector<int> input2 = {
		2,
		4
	};
};