#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

class SumOfAllSubsetXorTotals {
public:
    // 0 ms, faster than 100% : 8.09 MB, less than 100%
    int solution(vector<int> nums)
    {
        int n = size(nums);
        int ans = 0;
        int mask = 1;
        while (true) {
            int x = 0;

            for (size_t i = 0; i < n; i++) {
                if ((mask >> i) & 1)
                    x ^= nums[i];
            }

            ans += x;
            mask++;
            if (mask >> n)
                break;
        }

        return ans;
    }
    vector<int> output = {
        6,
        28,
        480
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 3 },
        { 5, 1, 6 },
        { 3, 4, 5, 6, 7, 8 }
    };
};