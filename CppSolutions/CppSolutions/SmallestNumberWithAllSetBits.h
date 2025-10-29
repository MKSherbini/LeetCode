#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/smallest-number-with-all-set-bits

class SmallestNumberWithAllSetBits {
public:
    // 0 ms, faster than 100% : 8.06 MB, less than 99.74%
    int solution(int n)
    {
        int t = n;
        for (int i = 1; t; i <<= 1) {
            n |= i;
            t >>= 1;
        }

        return n;
    }
    vector<int> output = {
        7,
        15,
        3
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        5,
        10,
        3
    };
};