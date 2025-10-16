#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations

class SmallestMissingNonNegativeIntegerAfterOperations {
public:
    // 0 ms, faster than 100% : 120.45 MB, less than 89.16%
    int solution(vector<int> nums, int value)
    {
        vector<int> f(value);
        for (auto x : nums) {
            f[(x % value + value) % value]++;
        }
        int mn = INT_MAX, it = 0;
        for (int i = 0; i < value; ++i) {
            if (f[i] < mn) {
                mn = f[i];
                it = i;
            }
        }

        return f[it] * value + it;
    }
    vector<int> output = {
        4,
        2
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, -10, 7, 13, 6, 8 },
        { 1, -10, 7, 13, 6, 8 }
    };
    vector<int> input2 = {
        5,
        7
    };
};