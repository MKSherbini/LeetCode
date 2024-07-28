#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/

class SecondMinimumTimeToReachDestination {
public:
    // 390 ms, faster than 92.8% : 186.72 MB, less than 73.7%
    int solution(int n, vector<vector<int>> edges, int time, int change)
    {
        int cycle = change * 2;

        vector<vector<int>> adj(n);
        for (auto& e : edges)
            adj[e[0] - 1].push_back(e[1] - 1),
                adj[e[1] - 1].push_back(e[0] - 1);

        queue<pair<int, int>> q;
        vector<int> dist(n, INT_MAX), dist2(n, INT_MAX), vis(n, 0);
        q.push({ 0, 0 });

        int f = 0;
        while (!empty(q)) {
            auto [i, t] = q.front();
            q.pop();
            Printer::print(i, t);
            vis[i]++;

            if (f && t > f && (i == n - 1))
                return Printer::print(f), t;
            else if (!f && i == n - 1)
                f = t;

            int mod = t % cycle;
            if (t && mod && mod >= change)
                t += cycle - mod;
            Printer::print("time: ", t, mod, cycle - mod);

            t += time;
            for (auto j : adj[i]) {
                if (vis[j] >= 2) // don't need to visit more than twice, n+2 is worst ans, we should find n+1
                    continue;

                if (dist[j] > t) {
                    dist2[j] = dist[j];
                    dist[j] = t;
                    q.push({ j, t });
                } else if (dist2[j] > t && dist[j] < t) {
                    dist2[j] = t;
                    q.push({ j, t });
                }
            }
        }

        return 66;
    }

    // hack failed, must do work...
    int solution2(int n, vector<vector<int>> edges, int time, int change)
    {
        int cycle = change * 2;

        vector<vector<int>> adj(n);
        for (auto& e : edges)
            adj[e[0] - 1].push_back(e[1] - 1),
                adj[e[1] - 1].push_back(e[0] - 1);

        queue<pair<int, int>> q;
        q.push({ 0, 0 });

        int f = 0;
        while (true) {
            auto [i, t] = q.front();
            q.pop();
            Printer::print(i, t);

            if (f && t > f && (i == n - 1))
                return Printer::print(f), t;
            else if (!f && i == n - 1)
                f = t;

            int mod = t % cycle;
            if (t && mod && mod >= change)
                t += cycle - mod;
            Printer::print("time: ", t, mod, cycle - mod);

            t += time;
            for (auto j : adj[i]) {
                q.push({ j, t });
            }
        }

        return 66;
    }
    vector<int> output = {
        13,
        11,
        5
    };
    static constexpr int const& inputs = 4;
    vector<int> input1 = {
        5,
        2,
        2
    };
    vector<vector<vector<int>>> input2 = {
        { { 1, 2 }, { 1, 3 }, { 1, 4 }, { 3, 4 }, { 4, 5 } },
        { { 1, 2 } },
        { { 1, 2 } }
    };
    vector<int> input3 = {
        3,
        3,
        1
    };
    vector<int> input4 = {
        5,
        2,
        2
    };
};