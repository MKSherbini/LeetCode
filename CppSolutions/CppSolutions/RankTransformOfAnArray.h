#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/rank-transform-of-an-array/description/

class RankTransformOfAnArray {
public:
    // 58 ms, faster than 84.22% : 42.93 MB, less than 70.17%
    vector<int> solution(vector<int> arr)
    {
        auto sorted(arr);
        sort(begin(sorted), end(sorted));
        unordered_map<int, int> m;
        int rank = 1;
        for (auto x : sorted) {
            if (!m[x])
                m[x] = rank++;
        }

        for (auto& x : arr)
            x = m[x];

        return arr;
    }
    vector<vector<int>> output = {
        { 4, 1, 2, 3 },
        { 1, 1, 1 },
        { 5, 3, 4, 2, 8, 6, 7, 1, 3 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 40, 10, 20, 30 },
        { 100, 100, 100 },
        { 37, 12, 28, 9, 100, 56, 80, 5, 12 }
    };
};