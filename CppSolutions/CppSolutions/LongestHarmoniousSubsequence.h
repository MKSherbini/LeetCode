#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-harmonious-subsequence

class LongestHarmoniousSubsequence {
public:
    // 6 ms, faster than 95.25% : 36.12 MB, less than 94.99%
    int solution(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        Printer::print(nums);
        int n = nums.size();
        int last = 0, lastNum = nums[0], cur = 1;
        int ans = 0;
        for (size_t i = 1; i < n; i++) {
            Printer::print(nums[i], last, cur);
            if (nums[i] == nums[i - 1]) {
                cur++;
            } else {
                lastNum = nums[i - 1];
                last = cur;
                cur = 1;
            }
            if (lastNum + 1 == nums[i]) {
                ans = max(ans, last + cur);
            }
        }

        return ans;
    }
    vector<int> output = {
        5,
        2,
        0,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 3, 2, 2, 5, 2, 3, 7 },
        { 1, 2, 3, 4 },
        { 1, 1, 1, 1 },
        { 62, 27, 90, 59, 63, 26, 40, 26, 72, 36 }
    };
};