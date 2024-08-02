#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/

class MinimumSwapsToGroupAll1sTogetherII {
public:
    // 60 ms, faster than 87.23% : 82.91 MB, less than 62.67%
    int solution(vector<int> nums)
    {
        int ones = count(begin(nums), end(nums), 1);

        int zeros = 0;
        int ans = INT_MAX;
        int n = size(nums);
        for (size_t i = 0; i < n * 2; i++) {
            zeros += nums[i % n] == 0;
            if (i >= ones) {
                zeros -= nums[(i - ones) % n] == 0;
            }
            if (i >= ones - 1) {
                ans = min(ans, zeros);
            }
        }

        return min(ans, zeros);
    }
    vector<int> output = {
        1,
        2,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 0, 1, 0, 1, 1, 0, 0 },
        { 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 1, 1, 0, 0, 1 }
    };
};