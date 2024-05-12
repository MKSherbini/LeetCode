#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

class LargestLocalValuesInAMatrix {
public:
    // 7 ms, faster than 89.64% : 13.44 MB, less than 81.76%
    vector<vector<int>> solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);

        vector ans(n - 2, vector(m - 2, 0));

        for (size_t i = 0; i < n - 2; i++) {
            for (size_t j = 0; j < m - 2; j++) {
                for (size_t ii = 0; ii <= 2; ii++) {
                    for (size_t jj = 0; jj <= 2; jj++) {
                        ans[i][j] = max(ans[i][j], grid[i + ii][j + jj]);
                    }
                }
            }
        }

        return ans;
    }
    vector<vector<vector<int>>> output = {
        { { 9, 9 }, { 8, 6 } },
        { { 2, 2, 2 }, { 2, 2, 2 }, { 2, 2, 2 } }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 9, 9, 8, 1 }, { 5, 6, 2, 6 }, { 8, 2, 6, 4 }, { 6, 2, 2, 2 } },
        { { 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1 }, { 1, 1, 2, 1, 1 }, { 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1 } }
    };
};