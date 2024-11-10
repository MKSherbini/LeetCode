#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii

class ShortestSubarrayWithOrAtLeastKII {
public:
    // 31 ms, faster than 94.51% : 88.11 MB, less than 89.97%
    int solution(vector<int> nums, int k)
    {
        vector<int> v(32);
        int pre = 0;
        int i = 0;
        int ans = INT_MAX;
        for (int j = 0; j < size(nums); j++) {
            pre |= nums[j];
            for (int bi = 0, b = 1; bi < 32; bi++, b <<= 1) {
                v[bi] += !!(nums[j] & b);
            }
            while (i <= j && pre >= k) {
                ans = min(ans, j - i + 1);
                for (int bi = 0, b = 1; bi < 32; bi++, b <<= 1) {
                    v[bi] -= !!(nums[i] & b);
                    if (!v[bi]) {
                        pre &= ~b;
                    }
                }
                i++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
    vector<int> output = {
        1,
        3,
        1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3 },
        { 2, 1, 8 },
        { 1, 2 }
    };
    vector<int> input2 = {
        2,
        10,
        0
    };
};