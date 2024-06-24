#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

class MinimumNumberOfKConsecutiveBitFlips {
public:
    // 78 ms, faster than 93.44% : 108.38 MB, less than 100%
    int solution(vector<int> nums, int k)
    {
        int n = size(nums);
        int ans = 0, flips = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] + flips) % 2 == 0) {
                if (i > n - k) {
                    return -1;
                } else {
                    ans++;
                    flips++;
                    nums[i] = -1;
                }
            }
            if (i + 1 >= k) {
                flips -= nums[i - k + 1] < 0;
            }
            Printer::print(flips, ans);
        }
        return ans;
    }
    vector<int> output = {
        2,
        -1,
        3
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 0, 1, 0 },
        { 1, 1, 0 },
        { 0, 0, 0, 1, 0, 1, 1, 0 }
    };
    vector<int> input2 = {
        1,
        2,
        3
    };
};