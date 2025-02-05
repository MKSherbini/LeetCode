#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class CheckIfOneStringSwapCanMakeStringsEqual {
public:
    // 0 ms, faster than 100% : 8.3 MB, less than 61.87%
    uint8_t solution(string s1, string s2)
    {
        int n = size(s1);
        vector<int> v;
        for (size_t i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                v.push_back(i);

            if (size(v) > 2)
                return 0;
        }

        if (empty(v))
            return 1;

        return s1[v[0]] == s2[v.back()] && s2[v[0]] == s1[v.back()];
    }
    vector<uint8_t> output = {
        true,
        false,
        true
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "bank",
        "attack",
        "kelb"
    };
    vector<string> input2 = {
        "kanb",
        "defend",
        "kelb"
    };
};