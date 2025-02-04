#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-ascending-subarray-sum

class MaximumAscendingSubarraySum {
public:
    // 0 ms, faster than 100% : 11.04 MB, less than 77.09%
    int solution(vector<int> nums)
    {
        int ans = 0, c = 0;
        for (size_t i = 0; i < size(nums); i++) {
            if (i > 0 && nums[i] > nums[i - 1]) {
                c += nums[i];
            } else {
                c = nums[i];
            }

            ans = max(ans, c);
        }

        return ans;
    }
    vector<int> output = {
        65,
        150,
        33
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 10, 20, 30, 5, 10, 50 },
        { 10, 20, 30, 40, 50 },
        { 12, 17, 15, 13, 10, 11, 12 }
    };
};