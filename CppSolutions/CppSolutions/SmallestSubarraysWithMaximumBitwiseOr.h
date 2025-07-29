#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or

class SmallestSubarraysWithMaximumBitwiseOr {
public:
    // 64 ms, faster than 26.72% : 73.8 MB, less than 18.97%
    vector<int> solution(vector<int> nums)
    {
        int n = nums.size();
        vector<vector<int>> v(32);
        vector<int> vi(32);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int j = 0; j < 32 && x; ++j) {
                if (x & 1) {
                    v[j].push_back(i);
                }
                x >>= 1;
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int last = i;
            for (int j = 0; j < 32; j++) {
                while (vi[j] < v[j].size() && v[j][vi[j]] < i) {
                    vi[j]++;
                }
                if (vi[j] < v[j].size()) {
                    last = max(last, v[j][vi[j]]);
                }
            }
            ans[i] = last - i + 1;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 3, 3, 2, 2, 1 },
        { 2, 1 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 0, 2, 1, 3 },
        { 1, 2 }
    };
};