#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i

class AdjacentIncreasingSubarraysDetectionI {
public:
    // 7 ms, faster than 94.69% : 40.28 MB, less than 92.92%
    uint8_t solution(vector<int> nums, int k)
    {
        int n = nums.size();
        k--;
        int len = 0, lastLen = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                len++;
            } else {
                lastLen = len;
                len = 0;
            }
            Printer::print(lastLen, len);
            if ((lastLen >= k && len >= k) || len + 1 >= (k + 1) * 2) {
                return true;
            }
        }
        return false;
    }
    vector<uint8_t> output = {
        true,
        false,
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 5, 7, 8, 9, 2, 3, 4, 3, 1 },
        { 1, 2, 3, 4, 4, 4, 4, 5, 6, 7 },
        { -15, -13, 4, 7 },
        { -15, 3, 16, 0 }
    };
    vector<int> input2 = {
        3,
        5,
        2,
        2
    };
};