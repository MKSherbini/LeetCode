#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

class MinimumNumberOfOperationsToMakeArrayXorEqualToK {
public:
    // 99 ms, faster than 87.96% : 91.2 MB, less than 98.6%
    int solution(vector<int> nums, int k)
    {
        int all = 0;
        for (auto x : nums)
            all ^= x;

        int ans = 0;
        while (all != k) {
            if ((all & 1) != (k & 1))
                ans++;
            all >>= 1;
            k >>= 1;
        }

        return ans;
    }
    vector<int> output = {
        2,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 1, 3, 4 },
        { 2, 0, 2, 0 }
    };
    vector<int> input2 = {
        1,
        0
    };
};