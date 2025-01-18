#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

class MinimumCostToMakeAtLeastOneValidPathInAGrid {
public:
    // 48 ms, faster than 39.8% : 26.86 MB, less than 33.47%
    int solution(vector<vector<int>> grid)
    {
        int n = size(grid), m = size(grid[0]);
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector vis(n, vector(m, INT_MAX));
        pq.push({ 0, 0, 0 });
        vis[0][0] = 0;
        while (!empty(pq)) {
            auto [c, i, j] = pq.top();
            Printer::print(pq.top());
            pq.pop();
            if (i == n - 1 && j == m - 1)
                return c;

            const vector<pair<int, int>> dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
            for (int k = 0; k < 4; k++) {
                auto& [dx, dy] = dir[k];
                int cost = (k != grid[i][j] - 1);
                if (valid(i + dx, n) && valid(j + dy, m)
                    && (vis[i + dx][j + dy] > vis[i][j] + cost)) {
                    vis[i + dx][j + dy] = vis[i][j] + cost;
                    pq.push({ vis[i + dx][j + dy], i + dx, j + dy });
                }
            }
        }

        return 66;
    }
    vector<int> output = {
        3,
        0,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 1, 1, 1 }, { 2, 2, 2, 2 }, { 1, 1, 1, 1 }, { 2, 2, 2, 2 } },
        { { 1, 1, 3 }, { 3, 2, 2 }, { 1, 1, 4 } },
        { { 1, 2 }, { 4, 3 } }
    };
};