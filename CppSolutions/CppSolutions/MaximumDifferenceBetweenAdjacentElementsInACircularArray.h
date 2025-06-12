#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array

class MaximumDifferenceBetweenAdjacentElementsInACircularArray {
public:
    // 0 ms, faster than 100% : 30.37 MB, less than 86.87%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        int ans = abs(nums[0] - nums.back());
        for (int i = 1; i < n; ++i) {
            int diff = abs(nums[i] - nums[i - 1]);
            ans = max(ans, diff);
        }

        return ans;
    }
    vector<int> output = {
        3,
        5
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 4 },
        { -5, -10, -5 }
    };
};