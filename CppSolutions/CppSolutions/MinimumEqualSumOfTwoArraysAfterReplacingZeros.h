#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros

class MinimumEqualSumOfTwoArraysAfterReplacingZeros {
public:
    // 123 ms, faster than 75.04% : 135.16 MB, less than 99.91%
    int solution(vector<int> nums1, vector<int> nums2)
    {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;
        for (int i : nums1) {
            if (i != 0) {
                sum1 += i;
            } else {
                z1++;
            }
        }
        for (int i : nums2) {
            if (i != 0) {
                sum2 += i;
            } else {
                z2++;
            }
        }
        sum1 += z1;
        sum2 += z2;
        if ((z1 == 0 && sum2 > sum1) || (z2 == 0 && sum1 > sum2)) {
            return -1;
        }

        return max(sum1, sum2);
    }
    vector<int> output = {
        12,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 3, 2, 0, 1, 0 },
        { 2, 0, 2, 0 }
    };
    vector<vector<int>> input2 = {
        { 6, 5, 0 },
        { 1, 4 }
    };
};