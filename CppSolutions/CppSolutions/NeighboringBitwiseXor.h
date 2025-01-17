#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/neighboring-bitwise-xor

class NeighboringBitwiseXor {
public:
    // 0 ms, faster than 100% : 263.81 MB, less than 74.77%
    uint8_t solution(vector<int> derived)
    {
        int ans = 0;
        for (auto x : derived)
            ans ^= x;
        
        return ans == 0;
    }
    vector<uint8_t> output = {
        true,
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 1, 0 },
        { 1, 1 },
        { 1, 0 }
    };
};