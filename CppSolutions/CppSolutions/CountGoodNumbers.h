#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-good-numbers

class CountGoodNumbers {
public:
    // 0 ms, faster than 100% : 7.79 MB, less than 96.37%
    int solution(long long n)
    {
        int mod = 1e9 + 7;
        auto f = [&](long long x, long long y) {
            long long res = 1;
            while (y > 0) {
                if (y & 1) {
                    res *= x;
                    res %= mod;
                }
                x *= x;
                x %= mod;
                y >>= 1;
            }
            return res;
        };

        return f(5, (n + 1) / 2) * f(4, n / 2) % mod;
    }
    vector<int> output = {
        5,
        400,
        564908303
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        1,
        4,
        50
    };
};