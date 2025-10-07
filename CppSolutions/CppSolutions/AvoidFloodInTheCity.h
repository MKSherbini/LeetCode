#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/avoid-flood-in-the-city

class AvoidFloodInTheCity {
public:
    // 111 ms, faster than 84.05% : 114.51 MB, less than 72.93%
    vector<int> solution(vector<int> rains)
    {
        unordered_map<int, int> m;
        int n = rains.size();
        set<int> ava;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                ava.insert(i);
                continue;
            }

            if (m.count(rains[i])) {
                auto it = ava.upper_bound(m[rains[i]]);
                if (it == ava.end())
                    return {};
                ans[*it] = rains[i];
                ava.erase(it);
            }
            m[rains[i]] = i;
        }
        for (int i : ava)
            ans[i] = 1;

        return ans;
    }
    vector<vector<int>> output = {
        { -1, -1, -1, -1 },
        { -1, -1, 2, 1, -1, -1 },
        {}
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4 },
        { 1, 2, 0, 0, 2, 1 },
        { 1, 2, 0, 1, 2 }
    };
};