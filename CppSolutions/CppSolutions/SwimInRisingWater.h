#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/swim-in-rising-water

class SwimInRisingWater {
public:
    // 3 ms, faster than 88.24% : 13.79 MB, less than 59.32%
    int solution(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        vector visited(n, vector<int>(m, 1e7));
        pq.push({ grid[0][0], 0, 0 });
        visited[0][0] = grid[0][0];

        const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1)
                return t;

            for (auto [dx, dy] : dir) {
                int x = i + dx, y = j + dy;
                if (valid(x, n) && valid(y, m) && max(t, grid[x][y]) < visited[x][y]) {
                    visited[x][y] = max(t, grid[x][y]);
                    pq.push({ visited[x][y], x, y });
                }
            }
        }

        return -1;
    }
    vector<int> output = {
        3,
        16
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 0, 2 }, { 1, 3 } },
        { { 0, 1, 2, 3, 4 }, { 24, 23, 22, 21, 5 }, { 12, 13, 14, 15, 16 }, { 11, 17, 18, 19, 20 }, { 10, 9, 8, 7, 6 } }
    };
};