#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sort-matrix-by-diagonals

class SortMatrixByDiagonals {
public:
    // 3 ms, faster than 92.19% : 43.22 MB, less than 86.52%
    vector<vector<int>> solution(vector<vector<int>> grid)
    {
        int n = grid.size();

        for (int it = 0; it < n; it++) {
            int i = it, j = 0;
            vector<int> v;
            while (i < n && j < n) {
                v.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(v.begin(), v.end(), greater());
            i = it, j = 0;
            int k = 0;
            while (i < n && j < n) {
                grid[i][j] = v[k++];
                i++;
                j++;
            }
        }

        for (int it = 1; it < n; it++) {
            int i = 0, j = it;
            vector<int> v;
            while (i < n && j < n) {
                v.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(v.begin(), v.end());
            i = 0, j = it;
            int k = 0;
            while (i < n && j < n) {
                grid[i][j] = v[k++];
                i++;
                j++;
            }
        }

        return grid;
    }
    vector<vector<vector<int>>> output = {
        { { 8, 2, 3 }, { 9, 6, 7 }, { 4, 5, 1 } },
        { { 2, 1 }, { 1, 0 } },
        { { 1 } }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 7, 3 }, { 9, 8, 2 }, { 4, 5, 6 } },
        { { 0, 1 }, { 1, 2 } },
        { { 1 } }
    };
};