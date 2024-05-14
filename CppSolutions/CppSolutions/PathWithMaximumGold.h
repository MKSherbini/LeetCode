#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/path-with-maximum-gold/description/

class PathWithMaximumGold {
public:
    // 1538 ms, faster than 5.13% : 252.8 MB, less than 5.13%
    int solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        int ans = 0;
        function<void(int, int, int)> f = [&](int i, int j, int sum) -> void {
            if (!valid(i, n) || !valid(j, m) || !grid[i][j])
                return;

            int val = grid[i][j];
            sum += val;
            ans = max(ans, sum);
            grid[i][j] = 0;
            const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto [dx, dy] : dir) {
                f(i + dx, j + dy, sum);
            }

            grid[i][j] = val;
        };
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                f(i, j, 0);
            }
        }

        return ans;
    }
    vector<int> output = {
        24,
        28
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 0, 6, 0 }, { 5, 8, 7 }, { 0, 9, 0 } },
        { { 1, 0, 7 }, { 2, 0, 6 }, { 3, 4, 5 }, { 0, 3, 0 }, { 9, 0, 20 } }
    };
};