#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k

class MaximumSubarraySumWithLengthDivisibleByK {
public:
    // 0 ms, faster than 100% : 162.09 MB, less than 99.33%
    int solution(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<long long> modLowest(k, LLONG_MAX / 2);
        long long ans = LLONG_MIN, acc = 0;
        modLowest[k - 1] = 0;
        for (int i = 0; i < n; ++i) {
            acc += nums[i];
            ans = max(ans, acc - modLowest[i % k]);
            modLowest[i % k] = min(modLowest[i % k], acc);
            Printer::print(acc, ans);
            Printer::print(modLowest);
        }

        return ans;
    }
    vector<int> output = {
        3,
        -10,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2 },
        { -1, -2, -3, -4, -5 },
        { -5, 1, 2, -3, 4 }
    };
    vector<int> input2 = {
        1,
        4,
        2
    };
};