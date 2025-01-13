#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-length-of-string-after-operations

class MinimumLengthOfStringAfterOperations {
public:
    // 4 ms, faster than 98.39% : 31.94 MB, less than 86.69%
    int solution(string s)
    {
        vector<int> f(26);
        for (auto c : s) {
            f[c - 'a']++;
        }

        Printer::print(f);
        int ans = 0;
        for (size_t i = 0; i < 26; i++) {
            if (f[i] >= 3) {
                f[i] = 1 + (f[i] % 2 == 0);
            }
            ans += f[i];
        }
        Printer::print(f);

        return ans;
    }
    vector<int> output = {
        5,
        2
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "abaacbcbb",
        "aa"
    };
};