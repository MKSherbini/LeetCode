#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment

class LengthOfLongestVShapedDiagonalSegment {
public:
    // 1644 ms, faster than 28% : 453.82 MB, less than 16.5%
    int solution(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        const vector<pair<int, int>> dir = { { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 } };

        vector mem(n, vector(m, vector(2, vector(4, -1))));
        auto f = [&](this auto f, int i, int j, bool turned, int target, int dd) -> int {
            int x = i + dir[dd].first, y = j + dir[dd].second;
            if (!valid(x, n) || !valid(y, m))
                return 0;
            if (grid[x][y] != target)
                return 0;

            if (mem[i][j][turned][dd] != -1) {
                return mem[i][j][turned][dd];
            }

            Printer::print(i, j, turned, dd);
            int ret = f(x, y, turned, 2 - target, dd);
            if (!turned) {
                ret = max(ret, f(x, y, 1, 2 - target, (dd + 1) % 4));
            }

            return mem[i][j][turned][dd] = ret + 1;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, 1 + f(i, j, 0, 2, d));
                    }
                }
            }
        }

        return ans;
    }

    // TLE
    int solution2(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };

        vector mem(n, vector(m, vector(2, vector(5, vector(3, -1)))));
        auto f = [&](this auto f, int i, int j, int turned, int target, int dd) {
            if (!valid(i, n) || !valid(j, m))
                return 0;
            if (grid[i][j] != target)
                return 0;
            if (turned > 1)
                return 0;

            if (mem[i][j][turned][dd + 1][target] != -1) {
                return mem[i][j][turned][dd + 1][target];
            }

            Printer::print(i, j, turned, dd);
            int ret = 0;
            const vector<pair<int, int>> dir = { { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 } };
            for (int k = 0; k < dir.size(); k++) {
                // if (dd != -1 && (dir[dd] == pair { -dir[k].first, -dir[k].second }))
                if (dd != -1 && !(((dd + 1) % 4 == k) || dd == k))
                    continue;
                ret = max(ret, f(i + dir[k].first, j + dir[k].second, turned + (dd != k) - (dd == -1), target != 2 ? 2 : 0, k));
            }

            return mem[i][j][turned][dd + 1][target] = ret + 1;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, f(i, j, 0, 1, -1));
            }
        }

        return ans;
    }
    vector<int> output = {
        5,
        4,
        5,
        1,
        2,
        5
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 2, 2, 1, 2, 2 }, { 2, 0, 2, 2, 0 }, { 2, 0, 1, 1, 0 }, { 1, 0, 2, 2, 2 }, { 2, 0, 0, 2, 2 } },
        { { 2, 2, 2, 2, 2 }, { 2, 0, 2, 2, 0 }, { 2, 0, 1, 1, 0 }, { 1, 0, 2, 2, 2 }, { 2, 0, 0, 2, 2 } },
        { { 1, 2, 2, 2, 2 }, { 2, 2, 2, 2, 0 }, { 2, 0, 0, 0, 0 }, { 0, 0, 2, 2, 2 }, { 2, 0, 0, 2, 0 } },
        { { 1 } },
        { { 1, 1, 1, 2, 0, 0 }, { 0, 0, 0, 0, 1, 2 } }, // clockwise only !!
        {
            { 1, 0, 0, 2 },
            { 0, 2, 2, 2 },
            { 0, 2, 1, 1 },
            { 2, 2, 0, 2 },
            { 0, 0, 1, 1 },
            { 1, 0, 2, 2 } }
    };
};