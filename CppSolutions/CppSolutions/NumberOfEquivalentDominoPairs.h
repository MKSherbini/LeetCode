#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-equivalent-domino-pairs

class NumberOfEquivalentDominoPairs {
public:
    // 0 ms, faster than 100% : 26 MB, less than 98.75%
    int solution(vector<vector<int>> dominoes)
    {
        unordered_map<int, int> m;
        for (auto& d : dominoes) {
            m[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;
        }
        int ans = 0;
        for (auto& [k, v] : m) {
            ans += v * (v - 1) / 2;
        }
        return ans;
    }
    vector<int> output = {
        1,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2 }, { 2, 1 }, { 3, 4 }, { 5, 6 } },
        { { 1, 2 }, { 1, 2 }, { 1, 1 }, { 1, 2 }, { 2, 2 } }
    };
};