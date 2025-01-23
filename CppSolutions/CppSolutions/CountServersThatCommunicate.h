#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-servers-that-communicate

class CountServersThatCommunicate {
public:
    // 0 ms, faster than 100% : 26.54 MB, less than 73.97%
    int solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);
        vector<int> vn(n), vm(m);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                vn[i] += grid[i][j];
                vm[j] += grid[i][j];
            }
        }

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (grid[i][j] && (vn[i] > 1 || vm[j] > 1))
                    ans++;
            }
        }

        return ans;
    }
    vector<int> output = {
        0,
        3,
        4
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 0 }, { 0, 1 } },
        { { 1, 0 }, { 1, 1 } },
        { { 1, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } }
    };
};