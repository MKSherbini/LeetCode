#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-array-end

class MinimumArrayEnd {
public:
    // 0 ms, faster than 100% : 8.21 MB, less than 98.95%
    long long solution(int n, int x)
    {
        n--;
        long long ans = x;

        long long bj = 1;
        for (long long i = 0, b = 1; i < 64; i++, b <<= 1) {
            if (!!(x & b))
                continue;

            if (!!(n & bj))
                ans |= b;

            bj <<= 1;
        }

        return ans;
    }
    vector<int> output = {
        6,
        15,
        5
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        3,
        2,
        3
    };
    vector<int> input2 = {
        4,
        7,
        1
    };
};