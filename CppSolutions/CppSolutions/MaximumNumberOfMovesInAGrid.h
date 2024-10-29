#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid

class MaximumNumberOfMovesInAGrid {
public:
    // 83 ms, faster than 17.39% : 94.75 MB, less than 5.83%
    int solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);

        vector mem(n, vector(m, -1));
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        function<int(int, int)> f = [&](int i, int j) -> int {
            const vector<pair<int, int>> dir = { { -1, 1 }, { 0, 1 }, { 1, 1 } };

            if (mem[i][j] != -1)
                return mem[i][j];

            int ret = 0;
            for (auto [dx, dy] : dir) {
                if (valid(i + dx, n) && valid(j + dy, m) && grid[i][j] < grid[i + dx][j + dy])
                    ret = max(ret, 1 + f(i + dx, j + dy));
            }

            return mem[i][j] = ret;
        };

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, f(i, 0));
        }

        Printer::print(mem);
        return ans;
    }
    vector<int> output = {
        3,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 2, 4, 3, 5 }, { 5, 4, 9, 3 }, { 3, 4, 2, 11 }, { 10, 9, 13, 15 } },
        { { 3, 2, 4 }, { 2, 1, 9 }, { 1, 1, 7 } }
    };
};