#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid

class MinimumTimeToVisitACellInAGrid {
public:
    // 547 ms, faster than 35.3% : 100 MB, less than 40.16%
    int solution(vector<vector<int>> grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({ 0, 0, 0 });

        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        int n = size(grid), m = size(grid[0]);

        vector vis(n, vector(m, 0));
        while (!empty(pq)) {
            auto [d, i, j] = pq.top();
            Printer::print(pq.top());
            pq.pop();
            if (i == n - 1 && j == m - 1)
                return d;

            if (vis[i][j])
                continue;

            vis[i][j] = 1;
            d++;
            const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto [dx, dy] : dir) {
                if (valid(i + dx, n) && valid(j + dy, m)) {
                    int dif = (grid[i + dx][j + dy] - d);
                    if (dif <= 0)
                        pq.push({ d, i + dx, j + dy });
                    else
                        pq.push({ d + dif + dif % 2, i + dx, j + dy });
                }
            }
        }

        return -1;
    }
    vector<int> output = {
        7,
        -1
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 0, 1, 3, 2 }, { 5, 1, 2, 5 }, { 4, 3, 8, 6 } },
        { { 0, 2, 4 }, { 3, 2, 1 }, { 1, 0, 4 } }
    };
};