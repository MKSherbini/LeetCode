#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray

class LongestStrictlyIncreasingOrStrictlyDecreasingSubarray {
public:
    // 0 ms, faster than 100% : 27.67 MB, less than 99.12%
    int solution(vector<int> nums)
    {
        int n = size(nums);

        int ans = 0, cur = 0, dir = 0;
        int two = 0;
        for (size_t i = 1; i < n; i++) {
            int dir2 = 0;
            if (nums[i] > nums[i - 1])
                dir2 = 1;
            else if (nums[i] < nums[i - 1])
                dir2 = -1;

            if (dir2 != 0)
                two = 1;
            if (dir2 != 0 && dir == dir2)
                cur++;
            else
                cur = 0;

            Printer::print(nums[i], dir, dir2);
            dir = dir2;
            ans = max(ans, cur);
        }

        if (ans == 0)
            return two ? 2 : 1;

        return ans + 2;
    }
    vector<int> output = {
        2,
        1,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 4, 3, 3, 2 },
        { 3, 3, 3, 3 },
        { 3, 2, 1 }
    };
};