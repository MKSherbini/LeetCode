#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class FindTheCityWithTheSmallestNumberOfNeighborsAtAThresholdDistance {
public:
    // 185 ms, faster than 5.01% : 116.47 MB, less than 5.01%
    int solution(int n, vector<vector<int>> edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back({ e[1], e[2] }),
                adj[e[1]].push_back({ e[0], e[2] });

        vector mem(n, vector<bitset<100>>(distanceThreshold + 1));
        vector<int> vis(n, 1e5);
        function<bitset<100>(int, int)> f = [&](int i, int dis) -> bitset<100> {
            bitset<100> ret = mem[i][dis];
            if (ret.count())
                return ret;
            vis[i] = dis;

            ret.set(i);
            for (auto [j, c] : adj[i])
                if (i != j && vis[j] > dis + c && dis + c <= distanceThreshold)
                    ret |= f(j, dis + c);

            return ret;
        };

        int ans = 0, mn = 105;
        for (size_t i = 0; i < n; i++) {
            std::fill(begin(vis), end(vis), 1e5);
            int c = f(i, 0).count();
            if (mn >= c)
                ans = i, mn = c;
            Printer::print(i, c, mn);
        }
        Printer::print(adj);

        return ans;
    }
    vector<int> output = {
        3,
        0
    };
    static constexpr int const& inputs = 3;
    vector<int> input1 = {
        4,
        5
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1, 3 }, { 1, 2, 1 }, { 1, 3, 4 }, { 2, 3, 1 } },
        { { 0, 1, 2 }, { 0, 4, 8 }, { 1, 2, 3 }, { 1, 4, 2 }, { 2, 3, 1 }, { 3, 4, 1 } }
    };
    vector<int> input3 = {
        4,
        2
    };
};