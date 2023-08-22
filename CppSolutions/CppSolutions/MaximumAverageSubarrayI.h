#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-average-subarray-i/?envType=study-plan-v2&envId=leetcode-75

class MaximumAverageSubarrayI
{
public:
	// 127 ms, faster than 93.19% : 109.5 MB, less than 76.24%
	double solution(vector<int> nums, int k) {
		int n = size(nums);
		double t = 0, ans;
		for (size_t i = 0; i < k; i++) {
			t += nums[i];
		}
		t /= k;
		ans = t;

		for (size_t i = k; i < n; i++) {
			t *= k;
			t += nums[i];
			t -= nums[i - k];
			t /= k;
			ans = max(ans, t);
		}

		return ans;
	}
	vector<double> output = {
		12.75000,
		5.00000
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,12,-5,-6,50,3},
		{5}
	};
	vector<int> input2 = {
		4,
		1
	};
};