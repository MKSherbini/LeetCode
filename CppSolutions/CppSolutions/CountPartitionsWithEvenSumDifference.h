#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-partitions-with-even-sum-difference

class CountPartitionsWithEvenSumDifference {
public:
    // 0 ms, faster than 100% : 22.25 MB, less than 96.78%
    int solution(vector<int> nums)
    {
        int odd = 0;
        for (auto x : nums) {
            if (x % 2 == 1) {
                odd++;
            }
        }

        return odd % 2 ? 0 : nums.size() - 1;
    }
    vector<int> output = {
        4,
        0,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 10, 10, 3, 7, 6 },
        { 1, 2, 2 },
        { 2, 4, 6, 8 }
    };
};