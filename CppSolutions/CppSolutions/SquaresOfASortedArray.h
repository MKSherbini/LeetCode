#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/squares-of-a-sorted-array/

class SquaresOfASortedArray
{
public:
	// 14 ms, faster than 95.59% : 28.2 MB, less than 70.8%
	vector<int> solution(vector<int> nums) {
		int n = size(nums);

		int it = 0;
		int j = lower_bound(begin(nums), end(nums), 0) - begin(nums);
		int i = j - 1;
		vector<int> ans(n);

		while (i >= 0 && j < n) {
			ans[it++] = abs(nums[i]) < abs(nums[j]) ? pow(nums[i--], 2) : pow(nums[j++], 2);
		}
		while (i >= 0) {
			ans[it++] = pow(nums[i--], 2);
		}
		while (j < n) {
			ans[it++] = pow(nums[j++], 2);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{0,1,9,16,100},
		{4,9,9,49,121}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{-4,-1,0,3,10},
		{-7,-3,2,3,11}
	};
};