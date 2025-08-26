#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle

class MaximumAreaOfLongestDiagonalRectangle {
public:
    // 0 ms, faster than 100% : 29.27 MB, less than 77.05%
    int solution(vector<vector<int>> dimensions)
    {
        double dMax = 0;
        int ans = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            double diag = sqrt(dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1]);
            if (diag > dMax) {
                dMax = diag;
                ans = dimensions[i][0] * dimensions[i][1];
            } else if (abs(diag - dMax) < 1e-5) {
                ans = max(ans, dimensions[i][0] * dimensions[i][1]);
            }
        }

        return ans;
    }
    vector<int> output = {
        48,
        12
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 9, 3 }, { 8, 6 } },
        { { 3, 4 }, { 4, 3 } }
    };
};