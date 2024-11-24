#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-matrix-sum

class MaximumMatrixSum {
public:
    // 0 ms, faster than 100% : 38.17 MB, less than 99.32%
    int solution(vector<vector<int>> matrix)
    {
        long long ans = 0;
        int c = 0, mn = INT_MAX;
        for (auto& v : matrix)
            for (auto x : v)
                ans += abs(x), c += x < 0, mn = min(mn, abs(x));

        return c & 1 ? ans - 2 * mn : ans;
    }
    vector<int> output = {
        4,
        16
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, -1 }, { -1, 1 } },
        { { 1, 2, 3 }, { -1, -2, -3 }, { 1, 2, 3 } }
    };
};