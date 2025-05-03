#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

class MinimumDominoRotationsForEqualRow {
public:
    // 7 ms, faster than 34.91% : 115.41 MB, less than 48.71%
    int solution(vector<int> tops, vector<int> bottoms)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < tops.size(); ++i) {
            m[tops[i]]++;
            if (tops[i] != bottoms[i])
                m[bottoms[i]]++;
        }

        int mx = 0, el;
        for (auto& [k, v] : m) {
            if (v > mx) {
                mx = v;
                el = k;
            }
        }

        if (mx < tops.size()) {
            return -1;
        }

        int c = 0, c2 = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != el) {
                c++;
            }
            if (bottoms[i] != el) {
                c2++;
            }
        }

        return min(c, c2);
    }
    vector<int> output = {
        2,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 1, 2, 4, 2, 2 },
        { 3, 5, 1, 2, 3 }
    };
    vector<vector<int>> input2 = {
        { 5, 2, 6, 2, 3, 2 },
        { 3, 6, 3, 3, 4 }
    };
};