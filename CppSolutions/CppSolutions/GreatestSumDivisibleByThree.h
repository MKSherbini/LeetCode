#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/greatest-sum-divisible-by-three

class GreatestSumDivisibleByThree {
public:
    // 34 ms, faster than 49.6% : 36.79 MB, less than 53.58%
    int solution(vector<int> nums)
    {
        vector<int> dp(3, 0);
        for (int num : nums) {
            vector<int> temp = dp;
            for (int i = 0; i < 3; ++i) {
                int sum = temp[i] + num;
                dp[sum % 3] = max(dp[sum % 3], sum);
            }
        }
        return dp[0];

    }
    vector<int> output = {
        18,
        0,
        12
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 6, 5, 1, 8 },
        { 4 },
        { 1, 2, 3, 4, 4 }
    };
};