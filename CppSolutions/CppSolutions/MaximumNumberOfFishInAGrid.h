#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid

class MaximumNumberOfFishInAGrid {
public:
    // 6 ms, faster than 69% : 96.95 MB, less than 41.86%
    int solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        function<int(int, int)> f = [&](int i, int j) -> int {
            if (!valid(i, n) || !valid(j, m) || grid[i][j] == 0)
                return 0;

            const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            int ret = grid[i][j];
            grid[i][j] = 0;
            for (auto [dx, dy] : dir) {
                ret += f(i + dx, j + dy);
            }

            return ret;
        };

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (grid[i][j])
                    ans = max(ans, f(i, j));
            }
        }

        return ans;
    }
    vector<int> output = {
        7,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 0, 2, 1, 0 }, { 4, 0, 0, 3 }, { 1, 0, 0, 4 }, { 0, 3, 2, 0 } },
        { { 1, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 1 } }
    };
};