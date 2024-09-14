#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

class LongestSubarrayWithMaximumBitwiseAnd {
public:
    // 93 ms, faster than 87.06% : 84.88 MB, less than 77.85%
    int solution(vector<int> nums)
    {
        int ans = 0;
        int mx = 0, cur = 0;
        for (int x : nums) {
            if (mx < x) {
                mx = x;
                ans = cur = 0;
            }

            if (mx == x) {
                cur++;
            } else {
                cur = 0;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
    vector<int> output = {
        2,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 3, 2, 2 },
        { 1, 2, 3, 4 }
    };
};