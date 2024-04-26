#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-falling-path-sum-ii/

class MinimumFallingPathSumII {
public:
    // 899 ms, faster than 5.26% : 19.2 MB, less than 9.94%
    int solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);
        vector mem(n, vector(m + 1, -1));
        function<int(int, int)> f = [&](int i, int last) -> int {
            if (i == n)
                return 0;

            int& ret = mem[i][last + 1];
            if (ret != -1)
                return ret;

            ret = 1e6;

            for (size_t j = 0; j < m; j++) {
                if (last == j)
                    continue;

                ret = min(ret, grid[i][j] + f(i + 1, j));
            }

            return ret;
        };

        return f(0, -1);
    }
    vector<int> output = {
        13,
        7
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
        { { 7 } }
    };
};