#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes

class MaximumManhattanDistanceAfterKChanges {
public:
    // 379 ms, faster than 9.7% : 38.56 MB, less than 47.58%
    int solution(string s, int k)
    {
        unordered_map<char, int> m;
        int ans = 0;
        for (char c : s) {
            m[c]++;

            int t = 0;
            int mn = min(m['N'], m['S']), mx = max(m['N'], m['S']);
            int d = min(mn, k);
            mn -= d;
            t += mx + d - mn;

            mn = min(m['E'], m['W']), mx = max(m['E'], m['W']);
            d = min(mn, k - d);
            mn -= d;
            t += mx + d - mn;

            ans = max(ans, t);
        }

        return ans;
    }
    vector<int> output = {
        3,
        6
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "NWSE",
        "NSWWEW"
    };
    vector<int> input2 = {
        1,
        3
    };
};