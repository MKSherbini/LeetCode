#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-ways-to-split-array

class NumberOfWaysToSplitArray {
public:
    // 0 ms, faster than 100% : 89.25 MB, less than 79.17%
    int solution(vector<int> nums)
    {
        int n = size(nums);
        long long pre = accumulate(begin(nums), end(nums), 0ll);

        long long post = 0;
        int ans = 0;
        for (int i = n - 1; i > 0; i--) {
            pre -= nums[i];
            post += nums[i];
            ans += (pre >= post);
        }

        return ans;
    }
    vector<int> output = {
        2,
        2
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 10, 4, -8, 7 },
        { 2, 3, 1, 0 }
    };
};