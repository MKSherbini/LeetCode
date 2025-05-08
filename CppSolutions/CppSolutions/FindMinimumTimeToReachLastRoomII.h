#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii

class FindMinimumTimeToReachLastRoomII {
public:
    // 387 ms, faster than 58.65% : 139.36 MB, less than 39.45%
    int solution(vector<vector<int>> moveTime)
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({ 0, 0, 0 });
        vector<vector<int>> dist(moveTime.size(), vector<int>(moveTime[0].size(), INT_MAX));
        dist[0][0] = 0;

        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };
        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            Printer::print(time, x, y);
            pq.pop();
            if (x == moveTime.size() - 1 && y == moveTime[0].size() - 1) {
                return time;
            }

            const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (auto [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (valid(nx, moveTime.size()) && valid(ny, moveTime[0].size())) {
                    int newTime = max(time, moveTime[nx][ny]) + (nx + ny + 1) % 2 + 1;
                    if (newTime < dist[nx][ny]) {
                        dist[nx][ny] = newTime;
                        pq.push({ newTime, nx, ny });
                    }
                }
            }
        }

        return 666;
    }
    vector<int> output = {
        7,
        6,
        4
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 0, 4 }, { 4, 4 } },
        { { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
        { { 0, 1 }, { 1, 2 } }
    };
};