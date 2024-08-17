#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-distance-in-arrays/description/

class MaximumDistanceInArrays {
public:
    // 263 ms, faster than 17.45% : 118.38 MB, less than 23.11%
    int solution(vector<vector<int>> arrays)
    {
        vector<pair<int, int>> v;
        for (size_t i = 0; i < size(arrays); i++) {
            v.push_back({ arrays[i].back(), i });
            v.push_back({ arrays[i][0], i });
        }
        sort(begin(v), end(v));

        if (v[0].second != v.back().second)
            return v.back().first - v[0].first;

        return max(v.back().first - v[1].first, v[size(v) - 2].first - v[0].first);
    }
    vector<int> output = {
        4,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2, 3 }, { 4, 5 }, { 1, 2, 3 } },
        { { 1 }, { 1 } }
    };
};