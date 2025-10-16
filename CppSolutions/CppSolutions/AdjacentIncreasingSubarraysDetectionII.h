#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii

class AdjacentIncreasingSubarraysDetectionII {
public:
    // 211 ms, faster than 90.33% : 173.37 MB, less than 100%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        int len = 0, lastLen = 0;
        int k = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                len++;
            } else {
                lastLen = len;
                len = 0;
            }
            Printer::print(lastLen, len);
            k = max(k, (len + 1) / 2);
            k = max(k, 1 + min(len, lastLen));
        }

        return k;
    }
    vector<int> output = {
        3,
        2
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 5, 7, 8, 9, 2, 3, 4, 3, 1 },
        { 1, 2, 3, 4, 4, 4, 4, 5, 6, 7 }
    };
};