#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i

class FindTheMinimumAreaToCoverAllOnesI {
public:
    // 252 ms, faster than 72.84% : 133.39 MB, less than 86.9%
    int solution(vector<vector<int>> grid)
    {
        int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
    vector<int> output = {
        6,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 0, 1, 0 }, { 1, 0, 1 } },
        { { 1, 0 }, { 0, 0 } }
    };
};