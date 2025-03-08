#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks

class MinimumRecolorsToGetKConsecutiveBlackBlocks {
public:
    // 0 ms, faster than 100% : 8.35 MB, less than 62.68%
    int solution(string blocks, int k)
    {
        int n = blocks.size();
        int w = 0;
        for (size_t i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                w++;
            }
        }

        int ans = w;
        for (size_t i = k; i < n; i++) {
            w += blocks[i] == 'W';
            w -= blocks[i - k] == 'W';
            ans = min(ans, w);
        }

        return ans;
    }
    vector<int> output = {
        3,
        0
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "WBBWWBBWBW",
        "WBWBBBW"
    };
    vector<int> input2 = {
        7,
        2
    };
};