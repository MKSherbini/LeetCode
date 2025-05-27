#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference

class DivisibleAndNonDivisibleSumsDifference {
public:
    // 0 ms, faster than 100% : 8.3 MB, less than 94.16%
    int solution(int n, int m)
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % m == 0) {
                ans -= i;
            } else {
                ans += i;
            }
        }
        return ans;
    }
    vector<int> output = {
        19,
        15,
        -15
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        10,
        5,
        5
    };
    vector<int> input2 = {
        3,
        6,
        1
    };
};