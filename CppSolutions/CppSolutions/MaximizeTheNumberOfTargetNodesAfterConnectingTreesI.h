#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i

class MaximizeTheNumberOfTargetNodesAfterConnectingTreesI {
public:
    // 419 ms, faster than 24.53% : 61.05 MB, less than 81.94%
    vector<int> solution(vector<vector<int>> edges1, vector<vector<int>> edges2, int k)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj(n), adj2(m);
        for (const auto& edge : edges1) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(m, 0);
        function<int(int, int, vector<vector<int>>&)> f = [&](int node, int left, vector<vector<int>>& adj) -> int {
            if (left == 0 || vis[node]) {
                return 0;
            }
            left--;

            vis[node] = 1;
            int ret = 1;
            for (int neighbor : adj[node]) {
                ret += f(neighbor, left, adj);
            }

            vis[node] = 0;
            return ret;
        };

        int mx2 = 0;
        for (size_t i = 0; i < m; i++) {
            int count = f(i, k, adj2);
            mx2 = max(mx2, count);
            Printer::print(i, count);
        }

        vis.assign(n, 0);
        vector<int> ans(n);
        for (size_t i = 0; i < n; i++) {
            int count = f(i, k + 1, adj);
            ans[i] = count + mx2;
            Printer::print(i, count);
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 9, 7, 9, 8, 8 },
        { 6, 3, 3, 3, 3 }
    };
    static constexpr int const& inputs = 3;
    vector<vector<vector<int>>> input1 = {
        { { 0, 1 }, { 0, 2 }, { 2, 3 }, { 2, 4 } },
        { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 } }
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 2, 7 }, { 1, 4 }, { 4, 5 }, { 4, 6 } },
        { { 0, 1 }, { 1, 2 }, { 2, 3 } }
    };
    vector<int> input3 = {
        2,
        1
    };
};