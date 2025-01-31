#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups

class DivideNodesIntoTheMaximumNumberOfGroups {
public:
    // 121 ms, faster than 90.27% : 58.56 MB, less than 31.9%
    int solution(int n, vector<vector<int>> edges)
    {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        function<int(int)> d = [&](int st) -> int {
            queue<int> q;
            vector<int> vis(n);
            q.push(st);
            vis[st] = 1;
            int d = 0;
            while (!empty(q)) {
                int c = size(q);
                d++;
                while (c--) {
                    auto i = q.front();
                    q.pop();

                    for (auto j : adj[i]) {
                        if (!vis[j])
                            q.push(j), vis[j] = 1;
                    }
                }
            }
            return d;
        };

        function<int(int)> f = [&](int st) -> int {
            queue<int> q;
            vector<int> vis(n);
            q.push(st);
            vis[st] = 1;
            int mx = 0;
            while (!empty(q)) {
                int c = size(q);
                while (c--) {
                    auto i = q.front();
                    mx = max(mx, d(i));
                    q.pop();

                    for (auto j : adj[i]) {
                        if (!vis[j])
                            q.push(j), vis[j] = 1;
                    }
                }
            }
            return mx;
        };

        vector<int> colors(n, -1);
        function<bool(int, int, bool)> b = [&](int i, int p, bool c) -> bool {
            if (colors[i] == !c)
                return false;
            if (colors[i] != -1)
                return true;
            colors[i] = c;

            for (auto j : adj[i]) {
                if (j != p && !b(j, i, !c))
                    return false;
            }

            return true;
        };

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            if (colors[i] != -1)
                continue;

            if (!b(i, -1, 0))
                return -1;
            ans += f(i);
        }

        return ans;
    }
    vector<int> output = {
        4,
        -1,
        2
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        6,
        3,
        2
    };
    vector<vector<vector<int>>> input2 = {
        { { 1, 2 }, { 1, 4 }, { 1, 5 }, { 2, 6 }, { 2, 3 }, { 4, 6 } },
        { { 1, 2 }, { 2, 3 }, { 3, 1 } },
        { { 1, 2 } }
    };
};