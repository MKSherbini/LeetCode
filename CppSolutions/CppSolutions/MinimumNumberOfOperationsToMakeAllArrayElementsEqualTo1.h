#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1

class MinimumNumberOfOperationsToMakeAllArrayElementsEqualTo1 {
public:
    // 0 ms, faster than 100% : 31.55 MB, less than 93.06%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        int gcdAll = 0;
        int ones = 0;
        for (int num : nums) {
            gcdAll = gcd(gcdAll, num);
            if (num == 1) {
                ones++;
            }
        }
        if (gcdAll != 1) {
            return -1;
        }

        if (ones > 0) {
            return n - ones;
        }

        int mnPath = n;
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = i; j < n; j++) {
                curr = gcd(curr, nums[j]);
                if (curr == 1) {
                    mnPath = min(mnPath, j - i);
                    break;
                }
            }
        }

        return mnPath + n - 1;
    }
    vector<int> output = {
        4,
        -1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 6, 3, 4 },
        { 2, 10, 6, 14 }
    };
};