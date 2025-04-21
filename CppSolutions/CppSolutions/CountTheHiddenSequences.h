#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-the-hidden-sequences

class CountTheHiddenSequences {
public:
    // 0 ms, faster than 100% : 112.41 MB, less than 97.66%
    int solution(vector<int> differences, int lower, int upper)
    {
        int n = differences.size();
        long long sum = 0;
        long long mn = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            sum += differences[i];
            mn = min(mn, sum);
            mx = max(mx, sum);
        }

        mx += lower - mn;

        return max(0LL, upper - mx + 1);
    }
    vector<int> output = {
        2,
        4,
        0
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 1, -3, 4 },
        { 3, -4, 5, 1, -2 },
        { 4, -7, 2 }
    };
    vector<int> input2 = {
        1,
        -4,
        3
    };
    vector<int> input3 = {
        6,
        5,
        6
    };
};