#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

class SumOfAbsoluteDifferencesInASortedArray
{
public:
	// 86 ms, faster than 82.7% : 83.5 MB, less than 91.62%
	vector<int> solution(vector<int> nums) {
		int n = size(nums);
		int sum = accumulate(begin(nums), end(nums), 0);

		vector<int> ans(n);
		int sumLess = 0;
		for (size_t i = 0; i < n; i++) {
			sum -= nums[i];
			ans[i] += sum - (n - i - 1) * nums[i];
			ans[i] += i * nums[i] - sumLess;
			sumLess += nums[i]; 
		}

		return ans;
	}
	vector<vector<int>> output = {
		{4,3,5},
		{24,15,13,15,21}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,3,5},
		{1,4,6,8,10}
	};
};