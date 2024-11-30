#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/valid-arrangement-of-pairs

class ValidArrangementOfPairs {
public:
    // 1771 ms, faster than 21.4% : 288.6 MB, less than 65.75%
    vector<vector<int>> solution(vector<vector<int>> pairs)
    {
        map<int, vector<int>> adj;
        unordered_map<int, int> in, out;

        for (auto& p : pairs) {
            adj[p[0]].push_back(p[1]);
            out[p[0]]++;
            in[p[1]]++;
        }

        vector<int> t;
        function<void(int)> f = [&](int node) {
            while (!adj[node].empty()) {
                int nextNode = adj[node].back();
                adj[node].pop_back();
                f(nextNode);
            }
            t.push_back(node);
        };

        int root = pairs[0][0];
        for (const auto& entry : out) {
            int node = entry.first;
            if (out[node] > in[node]) {
                root = node;
                break;
            }
        }

        f(root);

        vector<vector<int>> ans;
        for (int i = size(t) - 1; i > 0; i--) {
            ans.push_back({ t[i], t[i - 1] });
        }

        return ans;
    }
    vector<vector<vector<int>>> output = {
        { { 11, 9 }, { 9, 4 }, { 4, 5 }, { 5, 1 } },
        { { 1, 3 }, { 3, 2 }, { 2, 1 } },
        { { 1, 2 }, { 2, 1 }, { 1, 3 } }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 5, 1 }, { 4, 5 }, { 11, 9 }, { 9, 4 } },
        { { 1, 3 }, { 3, 2 }, { 2, 1 } },
        { { 1, 2 }, { 1, 3 }, { 2, 1 } }
    };
};