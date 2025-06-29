#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

class NumberOfSubsequencesThatSatisfyTheGivenSumCondition {
public:
    // 31 ms, faster than 62.49% : 54.21 MB, less than 56%
    int solution(vector<int> nums, int target)
    {
        sort(nums.begin(), nums.end());
        Printer::print(nums);

        int n = nums.size();
        int MOD = 1e9 + 7;

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        long long ans = 0;
        for (size_t i = 0; i < n; i++) {
            auto j = upper_bound(nums.begin() + i, nums.end(), target - nums[i]) - nums.begin();
            if (j <= i)
                break;
            ans += power[(j - i - 1)];
            ans %= MOD;
            Printer::print(i, j, nums[i], nums[j - 1]);
        }
        return ans;
    }
    vector<int> output = {
        4,
        6,
        61,
        272187084
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 3, 5, 6, 7 },
        { 3, 3, 6, 8 },
        { 2, 3, 3, 4, 6, 7 },
        { 14, 4, 6, 6, 20, 8, 5, 6, 8, 12, 6, 10, 14, 9, 17, 16, 9, 7, 14, 11, 14, 15, 13, 11, 10, 18, 13, 17, 17, 14, 17, 7, 9, 5, 10, 13, 8, 5, 18, 20, 7, 5, 5, 15, 19, 14 }
    };
    vector<int> input2 = {
        9,
        10,
        12,
        22
    };
};