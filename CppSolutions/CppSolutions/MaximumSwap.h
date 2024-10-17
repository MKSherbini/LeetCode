#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-swap/description/

class MaximumSwap {
public:
    // 0 ms, faster than 100% : 7.48 MB, less than 89.76%
    int solution(int num)
    {
        string s = to_string(num);
        for (size_t i = 0; i < size(s); i++) {
            int t = i;
            for (size_t j = i + 1; j < size(s); j++) {
                if (s[j] >= s[t])
                    t = j;
            }
            if (t != i && s[t] != s[i]) {
                swap(s[t], s[i]);
                break;
            }
        }

        return stoi(s);
    }
    vector<int> output = {
        7236,
        9973,
        98863
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        2736,
        9973,
        98368
    };
};