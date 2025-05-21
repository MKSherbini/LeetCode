#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes

class SetMatrixZeroes {
public:
    // 0 ms, faster than 100% : 18.52 MB, less than 78.87%
    vector<vector<int>> solution(vector<vector<int>> matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> row(n, 0), col(m, 0);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        return matrix;
    }
    vector<vector<vector<int>>> output = {
        { { 1, 0, 1 }, { 0, 0, 0 }, { 1, 0, 1 } },
        { { 0, 0, 0, 0 }, { 0, 4, 5, 0 }, { 0, 3, 1, 0 } }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } },
        { { 0, 1, 2, 0 }, { 3, 4, 5, 2 }, { 1, 3, 1, 5 } }
    };
};