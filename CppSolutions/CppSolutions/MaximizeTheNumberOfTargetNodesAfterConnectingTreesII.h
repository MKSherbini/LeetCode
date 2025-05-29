#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii

class MaximizeTheNumberOfTargetNodesAfterConnectingTreesII {
public:
    // 1146 ms, faster than 5.44% : 361.73 MB, less than 36.05%
    vector<int> solution(vector<vector<int>> edges1, vector<vector<int>> edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (const auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        vector<bool> odds(n);
        int mx = 0;
        function<void(int, int, int, vector<vector<int>>&)> f = [&](int node, int p, int d, vector<vector<int>>& adj) -> void {
            if (&adj == &adj1)
                odds[node] = d % 2;
            mx += d % 2;

            for (int neighbor : adj[node]) {
                if (neighbor != p) {
                    f(neighbor, node, d + 1, adj);
                }
            }
        };

        f(0, -1, 0, adj2);
        int mx2 = max(mx, m - mx);
        mx = 0;
        f(0, -1, 0, adj1);

        vector<int> ans(n);
        for (size_t i = 0; i < n; i++) {
            ans[i] = (odds[i] % 2 ? mx : n - mx) + mx2;
            Printer::print(i, ans[i]);
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 8, 7, 7, 8, 8 },
        { 3, 6, 6, 6, 6 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 0, 1 }, { 0, 2 }, { 2, 3 }, { 2, 4 } },
        { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 } }
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 2, 7 }, { 1, 4 }, { 4, 5 }, { 4, 6 } },
        { { 0, 1 }, { 1, 2 }, { 2, 3 } }
    };
};