#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-unguarded-cells-in-the-grid

class CountUnguardedCellsInTheGrid {
public:
    // 61 ms, faster than 56.7% : 172.07 MB, less than 84.31%
    int solution(int n, int m, vector<vector<int>> guards, vector<vector<int>> walls)
    {
        vector grid(n, vector(m, 0));
        for (auto& g : guards)
            grid[g[0]][g[1]] = 1;
        for (auto& w : walls)
            grid[w[0]][w[1]] = 2;

        Printer::print(grid);
        for (size_t i = 0; i < n; i++) {
            bool f = 0;
            for (size_t j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    f = 1;
                else if (grid[i][j] == 2)
                    f = 0;
                else if (grid[i][j] == 0 && f)
                    grid[i][j] = 3;
            }
        }
        for (size_t i = 0; i < n; i++) {
            bool f = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 1)
                    f = 1;
                else if (grid[i][j] == 2)
                    f = 0;
                else if (grid[i][j] == 0 && f)
                    grid[i][j] = 3;
            }
        }
        for (size_t j = 0; j < m; j++) {
            bool f = 0;
            for (size_t i = 0; i < n; i++) {
                if (grid[i][j] == 1)
                    f = 1;
                else if (grid[i][j] == 2)
                    f = 0;
                else if (grid[i][j] == 0 && f)
                    grid[i][j] = 3;
            }
        }
        for (size_t j = 0; j < m; j++) {
            bool f = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (grid[i][j] == 1)
                    f = 1;
                else if (grid[i][j] == 2)
                    f = 0;
                else if (grid[i][j] == 0 && f)
                    grid[i][j] = 3;
            }
        }

        Printer::print(grid);
        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    ans++;
            }
        }

        return ans;
    }
    vector<int> output = {
        7,
        4
    };
    static constexpr int const& inputs = 4;
    vector<int> input1 = {
        4,
        3
    };
    vector<int> input2 = {
        6,
        3
    };
    vector<vector<vector<int>>> input3 = {
        { { 0, 0 }, { 1, 1 }, { 2, 3 } },
        { { 1, 1 } }
    };
    vector<vector<vector<int>>> input4 = {
        { { 0, 1 }, { 2, 2 }, { 1, 4 } },
        { { 0, 1 }, { 1, 0 }, { 2, 1 }, { 1, 2 } }
    };
};