#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k

class MinimumOperationsToMakeArrayValuesEqualToK {
public:
    // 8 ms, faster than 84.28% : 32.2 MB, less than 70.13%
    int solution(vector<int> nums, int k)
    {
        int n = size(nums);
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (nums[i] < k) {
                return -1;
            }
            if (nums[i] != k) {
                s.insert(nums[i]);
            }
        }
        return s.size();
    }
    vector<int> output = {
        2,
        -1,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 5, 2, 5, 4, 5 },
        { 2, 1, 2 },
        { 9, 7, 5, 3 }
    };
    vector<int> input2 = {
        2,
        2,
        1
    };
};