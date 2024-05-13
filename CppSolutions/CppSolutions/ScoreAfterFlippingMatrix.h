#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/score-after-flipping-matrix/description/

class ScoreAfterFlippingMatrix {
public:
    // 0 ms, faster than 100% : 10.07 MB, less than 94.44%
    int solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);

        for (size_t i = 0; i < n; i++) {
            if (!grid[i][0]) {
                for (size_t j = 0; j < m; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        for (size_t j = 0; j < m; j++) {
            int c = 0;
            for (size_t i = 0; i < n; i++) {
                c += grid[i][j];
            }

            if (c * 2 < n) {
                for (size_t i = 0; i < n; i++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            int x = 0;
            for (size_t j = 0; j < m; j++) {
                x <<= 1;
                x |= grid[i][j];
            }
            ans += x;
        }

        return ans;
    }
    vector<int> output = {
        39,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 0, 0, 1, 1 }, { 1, 0, 1, 0 }, { 1, 1, 0, 0 } },
        { { 0 } }
    };
};