#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/first-completely-painted-row-or-column

class FirstCompletelyPaintedRowOrColumn {
public:
    // 0 ms, faster than 100% : 133.66 MB, less than 95.18%
    int solution(vector<int> arr, vector<vector<int>> mat)
    {
        int n = size(mat), m = size(mat[0]);
        vector<int> vn(n), vm(m);
        vector<pair<int, int>> v(n * m);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                v[mat[i][j]-1] = { i, j };
            }
        }

        for (size_t i = 0; i < size(arr); i++) {
            auto& [x, y] = v[arr[i]-1];

            vn[x]++, vm[y]++;

            if (vn[x] == n || vm[y] == m)
                return i;
        }

        return 66;
    }
    vector<int> output = {
        2,
        3
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 3, 4, 2 },
        { 2, 8, 7, 4, 1, 3, 5, 6, 9 }
    };
    vector<vector<vector<int>>> input2 = {
        { { 1, 4 }, { 2, 3 } },
        { { 3, 2, 5 }, { 1, 4, 6 }, { 8, 7, 9 } }
    };
};