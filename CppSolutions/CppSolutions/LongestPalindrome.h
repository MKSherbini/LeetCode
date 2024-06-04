#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-palindrome/description/

class LongestPalindrome {
public:
    // 0 ms, faster than 100% : 7.65 MB, less than 97.12%
    int solution(string s)
    {
        vector<int> f(58);
        for (auto c : s)
            f[c - 'A']++;

        bool c = 0;
        int ans = 0;
        for (auto cnt : f)
            c |= cnt & 1, ans += cnt & ~1;

        return ans + c;
    }
    vector<int> output = {
        7,
        1
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "abccccdd",
        "a"
    };
};