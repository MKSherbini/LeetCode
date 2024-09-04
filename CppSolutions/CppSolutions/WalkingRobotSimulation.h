#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/walking-robot-simulation/description/

class WalkingRobotSimulation {
public:
    // 51 ms, faster than 96.69% : 36.26 MB, less than 99.45%
    int solution(vector<int> commands, vector<vector<int>> obstacles)
    {
        const vector<pair<int, int>> dir = { { 0, 1 }, { 1, 0 }, { 0, -1 } ,{ -1, 0 } };
        int i = 0;

        const int OFFSET = 30001;

        unordered_set<int> s;
        for (auto& ob : obstacles) {
            s.insert(ob[0] * OFFSET + ob[1]);
        }
        Printer::print(s);

        int ans = 0;
        int x = 0, y = 0;
        for (auto c : commands) {
            if (c == -1)
                i++;
            else if (c == -2)
                i--;
            else {
                while (c--) {
                    x += dir[i].first, y += dir[i].second;
                    Printer::print(x, y);
                    if (s.count(x * OFFSET + y)) {
                        x -= dir[i].first, y -= dir[i].second;
                        break;
                    }
                }
                ans = max(ans, x * x + y * y);
            }
            i = (i + 4) % 4;
        }

        return ans;
    }

    // too long fk this
    int solution2(vector<int> commands, vector<vector<int>> obstacles)
    {
        const vector<pair<int, int>> dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
        int i = 0;

        sort(begin(obstacles), end(obstacles), [](const auto& x, const auto& y) {
            return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
        });

        auto obstacles2 = obstacles;
        sort(begin(obstacles2), end(obstacles2), [](const auto& x, const auto& y) {
            return x[1] == y[1] ? x[0] < y[0] : x[1] < y[1];
        });

        Printer::print(obstacles);
        Printer::print(obstacles2);

        int ans = 0;
        int x = 0, y = 0;
        for (auto c : commands) {
            if (c == -1)
                i++;
            else if (c == -2)
                i--;
            else {
                if (dir[i].first == 0) {
                    auto it = lower_bound(begin(obstacles), end(obstacles), vector { x, y });
                    if (dir[i].second > 0) {
                        if (it == end(obstacles) || next(it) == end(obstacles))
                            y += dir[i].second * c;
                        else
                            y += dir[i].second * min(c, (*next(it))[1] - 1);
                    } else {
                    }
                } else {
                }

                x += dir[i].first * c, y += dir[i].second * c;
                ans = max(ans, x * x + y * y);
            }
            i = (i + 4) % 4;

            Printer::print(ans, x, y);
        }

        return ans;
    }
    vector<int> output = {
        25,
        65,
        36
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, -1, 3 },
        { 4, -1, 4, -2, 4 },
        { 6, -1, -1, 6 }
    };
    vector<vector<vector<int>>> input2 = {
        {},
        { { 2, 4 }},
        {}
    };
};