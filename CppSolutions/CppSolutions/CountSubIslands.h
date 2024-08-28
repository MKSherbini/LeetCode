#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-sub-islands/description/

class CountSubIslands {
public:
    // 556 ms, faster than 17.58% : 157.9 MB, less than 21.01%
    int solution(vector<vector<int>> grid1, vector<vector<int>> grid2)
    {
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        int n = size(grid1), m = size(grid1[0]);
        bool bad = 0;
        function<void(int, int)> sink = [&](int i, int j) {
            grid2[i][j] = 0;
            if (grid1[i][j] == 0)
                bad = 1;
            const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto [dx, dy] : dir) {
                if (valid(i + dx, n)
                    && valid(j + dy, m)
                    && grid2[i + dx][j + dy] == 1)
                    sink(i + dx, j + dy);
            }
        };

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (grid2[i][j])
                    bad = 0, sink(i, j), ans += !bad;
            }
        }

        return ans;
    }

    // 521 ms, faster than 18.15% : 151.12 MB, less than 22.08%
    int solution2(vector<vector<int>> grid1, vector<vector<int>> grid2)
    {
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        int n = size(grid1), m = size(grid1[0]);
        function<void(int, int)> sink = [&](int i, int j) {
            grid2[i][j] = 0;

            const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto [dx, dy] : dir) {
                if (valid(i + dx, n)
                    && valid(j + dy, m)
                    && grid2[i + dx][j + dy] == 1)
                    sink(i + dx, j + dy);
            }
        };

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (grid2[i][j] && !grid1[i][j])
                    sink(i, j);
            }
        }

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (grid2[i][j])
                    ans++, sink(i, j);
            }
        }

        return ans;
    }
    vector<int> output = {
        3,
        2
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 1, 1, 1, 0, 0 }, { 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 1, 0, 1, 1 } },
        { { 1, 0, 1, 0, 1 }, { 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 }, { 1, 1, 1, 1, 1 }, { 1, 0, 1, 0, 1 } }
    };
    vector<vector<vector<int>>> input2 = {
        { { 1, 1, 1, 0, 0 }, { 0, 0, 1, 1, 1 }, { 0, 1, 0, 0, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 1, 0 } },
        { { 0, 0, 0, 0, 0 }, { 1, 1, 1, 1, 1 }, { 0, 1, 0, 1, 0 }, { 0, 1, 0, 1, 0 }, { 1, 0, 0, 0, 1 } }
    };
};