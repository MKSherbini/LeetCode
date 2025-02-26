#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

class MaximumAbsoluteSumOfAnySubarray {
public:
    // 0 ms, faster than 100% : 44.97 MB, less than 95.65%
    int solution(vector<int> nums)
    {
		int n = nums.size();
		int maxSum = 0;
		int minSum = 0;
		int maxSumSoFar = 0;
		int minSumSoFar = 0;
		for (int i = 0; i < n; i++)
		{
			maxSumSoFar = max(maxSumSoFar + nums[i], nums[i]);
			minSumSoFar = min(minSumSoFar + nums[i], nums[i]);
			maxSum = max(maxSum, maxSumSoFar);
			minSum = min(minSum, minSumSoFar);
		}
		return max(abs(maxSum), abs(minSum));
    }
    vector<int> output = {
        5,
        8
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, -3, 2, 3, -4 },
        { 2, -5, 1, -4, 3, -2 }
    };
};