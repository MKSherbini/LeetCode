#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer

class MaximumCountOfPositiveIntegerAndNegativeInteger {
public:
    // 0 ms, faster than 100% : 21.38 MB, less than 75.85%
    int solution(vector<int> nums)
    {
        int n = 0, p = 0;
        for (auto num : nums) {
            if (num < 0)
                n++;
            else if (num > 0)
                p++;
        }

        return max(n, p);
    }
    vector<int> output = {
        3,
        3,
        4
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { -2, -1, -1, 1, 2, 3 },
        { -3, -2, -1, 0, 0, 1, 2 },
        { 5, 20, 66, 1314 }
    };
};