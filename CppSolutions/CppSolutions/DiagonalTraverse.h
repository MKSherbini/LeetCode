#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/diagonal-traverse

class DiagonalTraverse {
public:
    // 0 ms, faster than 100% : 22.69 MB, less than 81.55%
    vector<int> solution(vector<vector<int>> mat)
    {
        int i = 0, j = 0;
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        int it = 0, total = n * m;
        for (int mx = 0; it < total; mx++) {
            if (mx % 2 == 0) {
                i = min(mx, n - 1);
                j = mx - i;
                while (i >= 0 && j < m) {
                    ans.push_back(mat[i][j]);
                    it++;
                    i--;
                    j++;
                }
            } else {
                j = min(mx, m - 1);
                i = mx - j;
                while (j >= 0 && i < n) {
                    ans.push_back(mat[i][j]);
                    it++;
                    i++;
                    j--;
                }
            }
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 1, 2, 4, 7, 5, 3, 6, 8, 9 },
        { 1, 2, 3, 4 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
        { { 1, 2 }, { 3, 4 } }
    };
};