#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-index-of-a-valid-split

class MinimumIndexOfAValidSplit {
public:
    // 0 ms, faster than 100% : 89.76 MB, less than 93.85%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        int dom = 0, freq = 0;
        for (int i = 0; i < n; i++) {
            if (dom == nums[i]) {
                freq++;
            } else if (freq > 0) {
                freq--;
            } else {
                dom = nums[i];
                freq = 1;
            }
        }

        freq = 0;
        for (int i = 0; i < n; i++) {
            if (dom == nums[i]) {
                freq++;
            }
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (dom == nums[i]) {
                cur++;
                freq--;
            }

            if (cur * 2 > i + 1 && freq * 2 > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
    vector<int> output = {
        2,
        4,
        -1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 2, 2 },
        { 2, 1, 3, 1, 1, 1, 7, 1, 2, 1 },
        { 3, 3, 3, 3, 7, 2, 2 }
    };
};