#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-triangular-sum-of-an-array

class FindTriangularSumOfAnArray {
public:
    // 54 ms, faster than 76.93% : 22.32 MB, less than 74.81%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        for (int len = n - 1; len >= 1; len--) {
            for (int i = 0; i < len; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }

        return nums[0];
    }
    vector<int> output = {
        8,
        5
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4, 5 },
        { 5 }
    };
};