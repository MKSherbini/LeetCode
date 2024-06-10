#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/height-checker/description/

class HeightChecker {
public:
    // 0 ms, faster than 100% : 10.01 MB, less than 78.64%
    int solution(vector<int> heights)
    {
        vector sorted(begin(heights), end(heights));
        sort(begin(sorted), end(sorted));
        
        int ans = 0;
        for (size_t i = 0; i < size(heights); i++) {
            ans += heights[i] != sorted[i];
        }

        return ans;
    }
    vector<int> output = {
        3,
        5,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 1, 4, 2, 1, 3 },
        { 5, 1, 2, 3, 4 },
        { 1, 2, 3, 4, 5 }
    };
};