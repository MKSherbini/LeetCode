#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-champion-ii

class FindChampionII {
public:
    // 9 ms, faster than 68.69% : 101.46 MB, less than 53.55%
    int solution(int n, vector<vector<int>> edges)
    {
        unordered_set<int> s;
        for (size_t i = 0; i < n; i++) {
            s.insert(i);
        }

        vector<vector<int>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]), s.erase(e[1]);

        if (size(s) != 1)
            return -1;

        vector<int> vis(n);
        function<int(int)> f = [&](int i) -> int {
            if (vis[i])
                return 0;

            vis[i] = 1;
            int c = 1;
            for (auto j : adj[i])
                c += f(j);

            return c;
        };

        return f(*s.begin()) == n ? *s.begin() : -1;
    }
    vector<int> output = {
        0,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        3,
        4
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1 }, { 1, 2 } },
        { { 0, 2 }, { 1, 3 }, { 1, 2 } }
    };
};