#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/smallest-integer-divisible-by-k

class SmallestIntegerDivisibleByK {
public:
    // 0 ms, faster than 100% : 7.7 MB, less than 80.92%
    int solution(int k)
    {
        int rem = 0;
        for (int i = 1; i <= k; ++i) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) {
                return i;
            }
        }
        return -1;
    }
    vector<int> output = {
        1,
        -1,
        3
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        1,
        2,
        3
    };
};