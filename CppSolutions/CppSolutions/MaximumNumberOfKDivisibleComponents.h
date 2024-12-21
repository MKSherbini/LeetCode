#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-k-divisible-components

class MaximumNumberOfKDivisibleComponents {
public:
    // 147 ms, faster than 47.47% : 179.08 MB, less than 43.04%
    int solution(int n, vector<vector<int>> edges, vector<int> values, int k)
    {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]),
                adj[e[1]].push_back(e[0]);
        }

        int ans = 0;
        function<int(int, int)> f = [&](int i, int p) -> int {
            int ret = values[i] % k;
            for (auto j : adj[i]) {
                if (p != j) {
                    ret += f(j, i);
                    ret %= k;
                }
            }

            if (!ret)
                ans++;

            return ret;
        };

        f(0, -1);
        return ans;
    }
    vector<int> output = {
        2,
        3
    };
    static constexpr int const& inputs = 4;
    vector<int> input1 = {
        5,
        7
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 2 }, { 1, 2 }, { 1, 3 }, { 2, 4 } },
        { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 1, 4 }, { 2, 5 }, { 2, 6 } }
    };
    vector<vector<int>> input3 = {
        { 1, 8, 1, 4, 4 },
        { 3, 0, 6, 1, 5, 2, 1 }
    };
    vector<int> input4 = {
        6,
        3
    };
};