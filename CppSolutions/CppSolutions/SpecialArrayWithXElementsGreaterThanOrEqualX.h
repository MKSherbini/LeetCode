#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

class SpecialArrayWithXElementsGreaterThanOrEqualX {
public:
    // 0 ms, faster than 100% : 10.01 MB, less than 85.84%
    int solution(vector<int> nums)
    {
        int n = size(nums);
        sort(begin(nums), end(nums));

        for (size_t i = 0; i < n; i++) {
            if (nums[i] >= n - i && (i == 0 || nums[i - 1] < n - i))
                return n - i;
        }

        return -1;
    }
    vector<int> output = {
        2,
        -1,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 5 },
        { 0, 0 },
        { 0, 4, 3, 0, 4 }
    };
};