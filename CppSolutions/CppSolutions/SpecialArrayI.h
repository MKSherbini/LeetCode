#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/special-array-i

class SpecialArrayI {
public:
    // 0 ms, faster than 100% : 27.66 MB, less than 61.71%
    uint8_t solution(vector<int> nums)
    {
        for (size_t i = 1; i < size(nums); i++) {
            if ((nums[i] & 1) == (nums[i - 1] & 1))
                return 0;
        }

        return 1;
    }
    vector<uint8_t> output = {
        true,
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1 },
        { 2, 1, 4 },
        { 4, 3, 1, 6 }
    };
};