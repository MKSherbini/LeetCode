#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/2-keys-keyboard/description/

class N2KeysKeyboard {
public:
    // 22 ms, faster than 23.86% : 156.74 MB, less than 14.76%
    int solution(int n)
    {
        if (n == 1)
            return 0;

        vector mem(n, vector(n, -1));
        function<int(int, int)> f = [&](int copy, int paste) -> int {
            if (copy == n)
                return 0;

            if (copy > n)
                return 2000;

            if (mem[copy][paste] != -1)
                return mem[copy][paste];

            return mem[copy][paste] = min(
                       2 + f(copy * 2, copy),
                       1 + f(copy + paste, paste));
        };

        return 1 + f(1, 1);
    }
    vector<int> output = {
        3,
        0
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        3,
        1
    };
};