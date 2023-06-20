#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/k-radius-subarray-averages/

class KRadiusSubarrayAverages
{
public:
	// 232 ms, faster than 93.61% : 129.8 MB, less than 94.24%
	vector<int> solution(vector<int> nums, int k) {
		int n = size(nums);
		vector ans(n, -1);

		long long sum = 0;
		for (size_t i = 0; i < n; i++) {
			sum += nums[i];
			if (i >= k * 2) {
				ans[i - k] = sum / (k * 2 + 1);
				sum -= nums[i - k * 2];
			}
		}

		return ans;
	}
	vector<vector<int>> output = {
		{-1,-1,-1,5,4,4,-1,-1,-1},
		{100000},
		{-1}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{7,4,3,9,1,8,5,2,6},
		{100000},
		{8}
	};
	vector<int> input2 = {
		3,
		0,
		100000
	};
};