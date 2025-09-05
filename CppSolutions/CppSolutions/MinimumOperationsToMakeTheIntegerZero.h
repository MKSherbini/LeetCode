#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero

class MinimumOperationsToMakeTheIntegerZero {
public:
    // 0 ms, faster than 100% : 8.1 MB, less than 85.04%
    int solution(int num1, int num2)
    {
        long long acc = num1;
        for (int i = 1;; i++) {
            acc -= num2;
            Printer::print(i, acc);
            if (acc < i) {
                return -1;
            }
            if (i >= __builtin_popcountll(acc)) {
                return i;
            }
        }

        return 66;
    }
    vector<int> output = {
        3,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        3,
        5
    };
    vector<int> input2 = {
        -2,
        7
    };
};