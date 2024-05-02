#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

class LargestPositiveIntegerThatExistsWithItsNegative {
public:
    // 7 ms, faster than 99.24% : 22.6 MB, less than 88.71%
    int solution(vector<int> nums)
    {
        sort(begin(nums), end(nums));

        int i = 0, j = size(nums) - 1;
        while (i < j && nums[i] < 0 && nums[j] > 0) {
            if (abs(nums[i]) == nums[j])
                return abs(nums[i]);
            else if (abs(nums[i]) < nums[j])
                j--;
            else
                i++;
        }

        return -1;
    }
    vector<int> output = {
        3,
        7,
        -1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { -1, 2, -3, 3 },
        { -1, 10, 6, 7, -7, 1 },
        { -10, 8, 6, 7, -2, -3 }
    };
};