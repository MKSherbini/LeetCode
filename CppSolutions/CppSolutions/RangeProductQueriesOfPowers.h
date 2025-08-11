#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/range-product-queries-of-powers

class RangeProductQueriesOfPowers {
public:
    // 0 ms, faster than 100% : 147.77 MB, less than 50.53%
    vector<int> solution(int n, vector<vector<int>> queries)
    {
        vector<int> v;
        for (size_t i = 1; i < INT_MAX; i <<= 1) {
            if (n & i) {
                v.push_back(i);
            }
        }

        int MOD = 1e9 + 7;
        int m = v.size();
        vector pre(m, vector<int>(m));
        for (size_t i = 0; i < m; i++) {
            pre[i][i] = v[i];
            for (size_t j = i + 1; j < m; j++) {
                pre[i][j] = (1LL * pre[i][j - 1] * v[j]) % MOD;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(pre[l][r]);
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 2, 4, 64 },
        { 2 }
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        15,
        2
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1 }, { 2, 2 }, { 0, 3 } },
        { { 0, 0 } }
    };
};