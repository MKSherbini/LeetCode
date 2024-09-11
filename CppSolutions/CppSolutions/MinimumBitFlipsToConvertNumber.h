#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

class MinimumBitFlipsToConvertNumber {
public:
    // 0 ms, faster than 100% : 7.48 MB, less than 93.51%
    int solution(int start, int goal)
    {
        int ans = 0;

        while (start || goal) {
            ans += (start & 1) ^ (goal & 1);
            start >>= 1, goal >>= 1;
        }
        
        return ans;
    }
    vector<int> output = {
        3,
        3
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        10,
        3
    };
    vector<int> input2 = {
        7,
        4
    };
};