#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class CheckIfArrayIsSortedAndRotated {
public:
    // 0 ms, faster than 100% : 11.04 MB, less than 85.73%
    uint8_t solution(vector<int> nums)
    {
        int c = nums.back() > nums[0];
        for (size_t i = 1; i < size(nums); i++) {
            if (nums[i] < nums[i - 1]) {
                c++;
                if (c > 1)
                    return 0;
            }
        }

        return 1;
    }
    vector<uint8_t> output = {
        true,
        false,
        true
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 4, 5, 1, 2 },
        { 2, 1, 3, 4 },
        { 1, 2, 3 }
    };
};