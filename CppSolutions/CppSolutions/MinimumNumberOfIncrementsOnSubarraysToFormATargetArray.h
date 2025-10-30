#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array

class MinimumNumberOfIncrementsOnSubarraysToFormATargetArray {
public:
    // 0 ms, faster than 100% : 76.81 MB, less than 88.01%
    int solution(vector<int> target)
    {
        int ans = target[0];
        for (size_t i = 1; i < target.size(); i++) {
            if (target[i] > target[i - 1]) {
                ans += target[i] - target[i - 1];
            }
        }
        return ans;
    }
    vector<int> output = {
        3,
        4,
        7
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 2, 1 },
        { 3, 1, 1, 2 },
        { 3, 1, 5, 4, 2 }
    };
};