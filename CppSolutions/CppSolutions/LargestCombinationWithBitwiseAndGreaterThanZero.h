#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero

class LargestCombinationWithBitwiseAndGreaterThanZero {
public:
    // 12 ms, faster than 94.78% : 60.03 MB, less than 88.86%
    int solution(vector<int> candidates)
    {
        vector<int> v(32);
        for (auto x : candidates) {
            for (int i = 0, b = 1; i < 32; i++, b <<= 1) {
                v[i] += !!(x & b);
            }
        }
        
        return *max_element(begin(v), end(v));
    }
    vector<int> output = {
        4,
        2
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 16, 17, 71, 62, 12, 24, 14 },
        { 8, 8 }
    };
};