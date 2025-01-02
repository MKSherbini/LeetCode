#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees

class FindMinimumDiameterAfterMergingTwoTrees {
public:
    // 371 ms, faster than 44.41% : 326.58 MB, less than 28.46%
    int solution(vector<vector<int>> edges1, vector<vector<int>> edges2)
    {
        auto adj1 = buildAdj(edges1), adj2 = buildAdj(edges2);
        int d = 0;
        f(adj1, 0, -1, d);
        int d2 = 0;
        f(adj2, 0, -1, d2);

        return max(max(d, d2), 1 + (d + 1) / 2 + (d2 + 1) / 2);
    }
    int f(vector<vector<int>>& adj, int i, int p, int& d)
    {
        int mx = 0, mx2 = 0;
        for (auto j : adj[i]) {
            if (j == p)
                continue;

            int ret = 1 + f(adj, j, i, d);

            if (ret > mx)
                mx2 = mx, mx = ret;
            else if (ret > mx2)
                mx2 = ret;
        }

        d = max(d, mx + mx2);

        return mx;
    }

    // 398 ms, faster than 40.3% : 330.56 MB, less than 24.54%
    int solution2(vector<vector<int>> edges1, vector<vector<int>> edges2)
    {
        int d = calcDia(buildAdj(edges1));
        int d2 = calcDia(buildAdj(edges2));

        return max(max(d, d2), 1 + (d + 1) / 2 + (d2 + 1) / 2);
    }

    vector<vector<int>> buildAdj(vector<vector<int>>& edges)
    {
        vector<vector<int>> ret(size(edges) + 1);
        for (auto edge : edges) {
            ret[edge[0]].push_back(edge[1]);
            ret[edge[1]].push_back(edge[0]);
        }

        return ret;
    }
    int calcDia(vector<vector<int>>&& adj)
    {
        int x;
        queue<pair<int, int>> q;

        q.push({ 0, -1 });
        while (!empty(q)) {
            int c = size(q);
            x = q.front().first;

            while (c--) {
                auto [i, p] = q.front();
                q.pop();

                for (auto j : adj[i]) {
                    if (j != p)
                        q.push({ j, i });
                }
            }
        }

        int dia = -1;
        q.push({ x, -1 });
        while (!empty(q)) {
            int c = size(q);
            dia++;

            while (c--) {
                auto [i, p] = q.front();
                q.pop();

                for (auto j : adj[i]) {
                    if (j != p)
                        q.push({ j, i });
                }
            }
        }

        return dia;
    }
    vector<int> output = {
        3,
        5
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 0, 1 }, { 0, 2 }, { 0, 3 } },
        { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 2, 4 }, { 2, 5 }, { 3, 6 }, { 2, 7 } }
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1 } },
        { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 2, 4 }, { 2, 5 }, { 3, 6 }, { 2, 7 } }
    };
};