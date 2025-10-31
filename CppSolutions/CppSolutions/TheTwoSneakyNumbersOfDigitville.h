#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville

class TheTwoSneakyNumbersOfDigitville {
public:
    // 0 ms, faster than 100% : 25.15 MB, less than 95.85%
    vector<int> solution(vector<int> nums)
    {
        int n = nums.size();
        vector<bool> f(n);

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (f[nums[i]]) {
                ans.push_back(nums[i]);
            }
            f[nums[i]] = true;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 0, 1 },
        { 2, 3 },
        { 4, 5 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 0, 1, 1, 0 },
        { 0, 3, 2, 1, 3, 2 },
        { 7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2 }
    };
};