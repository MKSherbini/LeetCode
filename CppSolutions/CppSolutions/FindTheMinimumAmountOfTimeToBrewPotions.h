#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions

class FindTheMinimumAmountOfTimeToBrewPotions {
public:
    // 103 ms, faster than 97.98% : 45.2 MB, less than 93.94%
    int solution(vector<int> skill, vector<int> mana)
    {
        int n = skill.size(), m = mana.size();
        vector<int> pre(n);
        pre[0] = skill[0];
        for (int i = 1; i < n; ++i)
            pre[i] = pre[i - 1] + skill[i];

        Printer::print(pre);
        int t = 0;
        for (int j = 1; j < m; j++) {
            long long mx = skill[0] * mana[j - 1];
            for (int i = 1; i < n; i++) {
                mx = max(mx, 1ll * pre[i] * mana[j - 1] - 1ll * pre[i - 1] * mana[j]);
            }
            t += mx;
        }

        return t + 1LL * pre.back() * mana.back();
    }
    vector<int> output = {
        110,
        5,

    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 5, 2, 4 },
        { 1, 1, 1 },

    };
    vector<vector<int>> input2 = {
        { 5, 1, 4, 2 },
        { 1, 1, 1 },

    };
};