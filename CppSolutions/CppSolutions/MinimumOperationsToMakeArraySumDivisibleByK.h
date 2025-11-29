#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k

class MinimumOperationsToMakeArraySumDivisibleByK {
public:
    // 0 ms, faster than 100% : 45.22 MB, less than 69.81%
    int solution(vector<int> nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum % k;
    }
    vector<int> output = {
        4,
        0,
        5
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 3, 9, 7 },
        { 4, 1, 3 },
        { 3, 2 }
    };
    vector<int> input2 = {
        5,
        4,
        6
    };
};