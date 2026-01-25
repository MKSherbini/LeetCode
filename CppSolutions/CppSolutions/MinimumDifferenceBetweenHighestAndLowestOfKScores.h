#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores

class MinimumDifferenceBetweenHighestAndLowestOfKScores {
public:
    // 0 ms, faster than 100% : 17.16 MB, less than 89.55%
    int solution(vector<int> nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n <= k) {
            return nums.back() - nums[0];
        }

        int ans = INT_MAX;
        for (size_t i = k - 1; i < n; i++) {
            ans = min(ans, nums[i] - nums[i - k + 1]);
        }

        return ans;
    }
    vector<int> output = {
        0,
        2
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 90 },
        { 9, 4, 1, 7 }
    };
    vector<int> input2 = {
        1,
        2
    };
};