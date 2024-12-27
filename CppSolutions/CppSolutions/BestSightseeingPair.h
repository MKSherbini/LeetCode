#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/best-sightseeing-pair

class BestSightseeingPair {
public:
    // 0 ms, faster than 100% : 45.31 MB, less than 69.53%
    int solution(vector<int> values)
    {
        int mx = values[0], ans = 0;

        for (int i = 1; i < size(values); i++) {
            int cur = values[i] - i;
            ans = max(ans, cur + mx);
            mx = max(mx, values[i] + i);
        }

        return ans;
    }
    vector<int> output = {
        11,
        2
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 8, 1, 5, 2, 6 },
        { 1, 2 }
    };
};