#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i

class DivideAnArrayIntoSubarraysWithMinimumCostI {
public:
    // 0 ms, faster than 100% : 30.37 MB, less than 96.48%
    int solution(vector<int> nums)
    {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
    vector<int> output = {
        6,
        12,
        12
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 12 },
        { 5, 4, 3 },
        { 10, 3, 1, 1 }
    };
};