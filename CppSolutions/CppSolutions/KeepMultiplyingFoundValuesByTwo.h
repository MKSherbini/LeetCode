#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/keep-multiplying-found-values-by-two

class KeepMultiplyingFoundValuesByTwo {
public:
    // 0 ms, faster than 100% : 13.97 MB, less than 89.2%
    int solution(vector<int> nums, int original)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        auto it = nums.begin();
        while ((it = lower_bound(it, nums.end(), original)) != nums.end() && *it == original) {
            original *= 2;
        }

        return original;
    }
    vector<int> output = {
        24,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 5, 3, 6, 1, 12 },
        { 2, 7, 9 }
    };
    vector<int> input2 = {
        3,
        4
    };
};