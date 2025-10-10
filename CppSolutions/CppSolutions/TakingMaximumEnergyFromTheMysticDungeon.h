#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon

class TakingMaximumEnergyFromTheMysticDungeon {
public:
    // 129 ms, faster than 86.27% : 146.87 MB, less than 75%
    int solution(vector<int> energy, int k)
    {
        int n = energy.size();
        vector<int> v(k);
        int ans = energy.back();
        for (int i = n - 1; i >= 0; i--) {
            v[i % k] += energy[i];
            ans = max(ans, v[i % k]);
        }

        return ans;
    }
    vector<int> output = {
        3,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 5, 2, -10, -5, 1 },
        { -2, -3, -1 }
    };
    vector<int> input2 = {
        3,
        2
    };
};