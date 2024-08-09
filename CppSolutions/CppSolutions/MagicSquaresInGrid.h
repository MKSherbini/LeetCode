#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/magic-squares-in-grid/description/

class MagicSquaresInGrid {
public:
    // 0 ms, faster than 100% : 11.68 MB, less than 31.51%
    int solution(vector<vector<int>> grid)
    {
        int ans = 0;
        string check1 = "4381672943816729";
        string check2 = "9276183492761834";
        for (int i = 0; i < (int)size(grid) - 2; i++) {
            for (int j = 0; j < (int)size(grid[0]) - 2; j++) {
                if (grid[i + 1][j + 1] == 5) {
                    string order = to_string(grid[i][j])
                        + to_string(grid[i][j + 1])
                        + to_string(grid[i][j + 2])
                        + to_string(grid[i + 1][j + 2])
                        + to_string(grid[i + 2][j + 2])
                        + to_string(grid[i + 2][j + 1])
                        + to_string(grid[i + 2][j])
                        + to_string(grid[i + 1][j]);

                    if (check1.find(order) != -1 || check2.find(order) != -1)
                        ans++;
                }
            }
        }

        return ans;
    }
    vector<int> output = {
        1,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 4, 3, 8, 4 }, { 9, 5, 1, 9 }, { 2, 7, 6, 2 } },
        { { 8 } }
    };
};