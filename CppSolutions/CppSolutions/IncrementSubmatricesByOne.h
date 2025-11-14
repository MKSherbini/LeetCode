#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/increment-submatrices-by-one

class IncrementSubmatricesByOne {
public:
    // 35 ms, faster than 56.7% : 86.31 MB, less than 89.72%
    vector<vector<int>> solution(int n, vector<vector<int>> queries)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (const auto& query : queries) {
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];
            for (int i = r1; i <= r2; ++i) {
                ans[i][c1] += 1;
                if (c2 + 1 < n)
                    ans[i][c2 + 1] -= 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                ans[i][j] += ans[i][j - 1];
            }
        }
        return ans;
    }
    vector<vector<vector<int>>> output = {
        { { 1, 1, 0 }, { 1, 2, 1 }, { 0, 1, 1 } },
        { { 1, 1 }, { 1, 1 } }
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        3,
        2
    };
    vector<vector<vector<int>>> input2 = {
        { { 1, 1, 2, 2 }, { 0, 0, 1, 1 } },
        { { 0, 0, 1, 1 } }
    };
};