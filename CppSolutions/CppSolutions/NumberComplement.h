#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-complement/description/

class NumberComplement {
public:
    // 0 ms, faster than 100% : 7.27 MB, less than 75.25%
    int solution(int num)
    {
        int t = num;
        int i = 1;
        while (t) {
            t &= ~1;
            t >>= 1;
            num ^= i;
            i <<= 1;
        }

        return num;
    }
    vector<int> output = {
        2,
        0
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        5,
        1
    };
};