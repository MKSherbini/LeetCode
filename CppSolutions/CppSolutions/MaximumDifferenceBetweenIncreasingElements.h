#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-difference-between-increasing-elements

class MaximumDifferenceBetweenIncreasingElements {
public:
    // 0 ms, faster than 100% : 11.71 MB, less than 91.69%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        int ans = -1;
        int mn = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > mn) {
                ans = max(ans, nums[i] - mn);
            } else {
                mn = min(mn, nums[i]);
            }
        }
        return ans;
    }
    vector<int> output = {
        4,
        -1,
        9
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 7, 1, 5, 4 },
        { 9, 4, 3, 2 },
        { 1, 5, 2, 10 }
    };
};