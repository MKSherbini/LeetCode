#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/

class FindValidMatrixGivenRowAndColumnSums {
public:
    // 32 ms, faster than 85.33% : 35.84 MB, less than 58.24%
    vector<vector<int>> solution(vector<int> rowSum, vector<int> colSum)
    {
        int n = size(rowSum), m = size(colSum);
        vector<vector<int>> ans(n, vector<int>(m));

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }

        return ans;
    }
    vector<vector<vector<int>>> output = {
        { { 3, 0 }, { 1, 7 } },
        { { 0, 5, 0 }, { 6, 1, 0 }, { 2, 0, 8 } }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 3, 8 },
        { 5, 7, 10 }
    };
    vector<vector<int>> input2 = {
        { 4, 7 },
        { 8, 6, 8 }
    };
};