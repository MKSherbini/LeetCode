#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/making-a-large-island

class MakingALargeIsland {
public:
    // 941 ms, faster than 9.64% : 398.35 MB, less than 5%
    int solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        int g = 2, glen = 0;
        function<int(int, int)> f = [&](int i, int j) -> int {
            if (!valid(i, n) || !valid(j, m) || grid[i][j] != 1)
                return 0;
            grid[i][j] = g;

            int ret = 1;
            const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto [dx, dy] : dir) {
                ret += f(i + dx, j + dy);
            }

            return ret;
        };

        function<void(int, int)> r = [&](int i, int j) -> void {
            if (!valid(i, n) || !valid(j, m) || grid[i][j] != g)
                return;
            grid[i][j] = g;

            const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto [dx, dy] : dir) {
                r(i + dx, j + dy);
            }
        };

        int ans = 0;
        unordered_map<int, int> mp;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    glen = f(i, j);
                    mp[g] = glen;
                    g++;
                    ans = max(ans, glen);
                }
            }
        }

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> s;
                    const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
                    for (auto [dx, dy] : dir) {
                        if (valid(i + dx, n) && valid(j + dy, m)) {
                            s.insert(grid[i + dx][j + dy]);
                        }
                    }

                    int sum = 1;
                    for (auto x : s) {
                        sum += mp[x];
                    }

                    ans = max(ans, sum);
                }
            }
        }
        Printer::print(mp);
        Printer::print(grid);

        return ans;
    }
    vector<int> output = {
        3,
        4,
        4
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 0 }, { 0, 1 } },
        { { 1, 1 }, { 1, 0 } },
        { { 1, 1 }, { 1, 1 } }
    };
};