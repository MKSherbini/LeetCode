#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/zero-array-transformation-i

class ZeroArrayTransformationI {
public:
    // 0 ms, faster than 100% : 292.66 MB, less than 96.48%
    uint8_t solution(vector<int> nums, vector<vector<int>> queries)
    {
        int n = nums.size();
        vector<int> v(n);
        for (auto& q : queries) {
            v[q[0]]++;
            if (q[1] + 1 < n) {
                v[q[1] + 1]--;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                v[i] += v[i - 1];
            }
            if (nums[i] - v[i] > 0) {
                return false;
            }
        }

        return true;
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 0, 1 },
        { 4, 3, 2, 1 }
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 2 } },
        { { 1, 3 }, { 0, 2 } }
    };
};